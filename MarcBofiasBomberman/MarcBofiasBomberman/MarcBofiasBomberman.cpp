#include "pch.h"
#include <iostream>
#include "Map.h"
#include "Bomberman.h"
#include "Powerup.h"
#include "Shield.h"
#include "Explosive.h"
#include "Box.h"
#include <stdlib.h>
#include <math.h>
#include <thread>
#include "Console.h"
#include "Enemy.h"
#include "GameManager.h"

int main()
{
	srand((unsigned)time(NULL));

	//--------------DECLARACIÓN DE VARIABLES/OBJETOS--------------------

	const int maxEnemies = 4, maxBoxes = 8, collectables = 2, spawnBox = 4;
	int contadorBomba = 0;
	bool destroyed[maxBoxes] = { false, false, false, false, false, false, false, false };

	Shield shield[collectables];
	PowerUp powerup[collectables];
	GameManager gm;
	Map map;
	Bomberman player(Vector2D(1, 1), 'O');
	Enemy enemy[maxEnemies];
	Box box[maxBoxes];
	Console consola;
	Explosive bomb('B');

	//--------------PREPARACIÓN DEL JUEGO--------------------

	//Se reinicia el mapa por defecto y se dibuja su forma en la pantalla. 
	//Después se escribe la leyenda que explica que representa cada símbolo.
	map.Reset();
	map.Draw(consola);
	gm.DrawLegend(consola);

	//Se colocan las cajas en el mapa, asegurandonos de que no coincidan con la posición del jugador.
	for (int b = 0; b < maxBoxes; b++)
	{
		gm.InitBox(map, box[b], player);
		box[b].SetNumber(b);
	}

	//Se le asigna a los coleccionables un numero, que coincide con el numero de una de las cajas
	//de manera que cada coleccionable puede aparecer en 2 cajas de las 8 que hay,
	//así que habrá 8 cajas y 4 coleccionables por partida, 2 powerups y 2 shields.
	//Después igualamos sus posiciones con la posición de la caja en cuestión
	for (int c = 0; c < collectables; c++)
	{
		shield[c].SetNumber(rand() % 2 + (c * 2));
		shield[c].position.x = box[shield[c].GetNumber()].position.x;
		shield[c].position.y = box[shield[c].GetNumber()].position.y;

		powerup[c].SetNumber(rand() % 2 + ((c + 2) * 2));
		powerup[c].position.x = box[powerup[c].GetNumber()].position.x;
		powerup[c].position.y = box[powerup[c].GetNumber()].position.y;
	}

	//Colocamos a los enemigos, siempre aparecen en la misma fila, con 2 columnas de diferencia.
	for (int e = 0; e < maxEnemies; e++)
		enemy[e].position.x = (e + 1) * 2;

	//----------------------------BUCLE DE JUEGO-----------------------------

	while (!gm.GetWin() && player.GetAlive())
	{
		//Lo primero que dibuja son las cajas.
		for (int b = 0; b < maxBoxes; b++)
			if (box[b].GetEnabled())
				box[b].Draw(map, consola);

		//Segundo dibuja los coleccionables y comprueba si el jugador ha recogido algún powerup o escudo.
		for (int c = 0; c < collectables; c++)
		{
			if (shield[c].GetEnabled())
			{
				shield[c].Draw(consola);
				gm.PickupShield(player, shield[c]);
			}
			if (powerup[c].GetEnabled())
			{
				powerup[c].Draw(consola);
				gm.PickupPowerup(player, powerup[c]);
			}
		}

		//Mueve y dibuja al jugador.
		player.MovementInput(map, consola, bomb);
		player.Draw(consola);

		//Mueve y dibuja a los enemigos, después comprueba si el enemigo ha alcanzado al player.
		for (int e = 0; e < maxEnemies; e++)
		{
			enemy[e].Movement(consola, map);
			enemy[e].Draw(consola);
			gm.EnemyImpact(player, enemy[e]);
		}

		//Solo se entra en este "if" si hay una bomba, 
		//cuando hay una bomba se encarga de contar el tiempo que tarda en explotar la bomba, el tiempo que dura la explosión
		//y de comprobar si algun elemento destruible, un enemigo o el jugador, han recibido el impacto de la bomba
		if (player.GetCountdown())
		{
			contadorBomba++;
			bomb.Countdown(map, consola, contadorBomba);

			if (bomb.GetBoom())
			{
				gm.BoomBomberman(map, bomb, player);

				for (int e = 0; e < maxEnemies; e++)
					gm.BoomEnemy(map, bomb, enemy[e]);

				for (int b = 0; b < maxBoxes; b++)
				{
					gm.BoomBox(map, bomb, box[b], destroyed[b]);
				}
				for (int c = 0; c < collectables; c++)
				{
					gm.BoomCollectable(map, bomb, shield[c]);
					gm.BoomCollectable(map, bomb, powerup[c]);
				}
			}

			if (contadorBomba == 15)
			{
				player.SetCountdown(false);
				contadorBomba = 0;

				for (int b = 0; b < maxBoxes; b++)
					if (destroyed[b])
						for (int c = 0; c < collectables; c++)
						{
							gm.CollectableSpawn(box[b], shield[c], destroyed[b]);
							gm.CollectableSpawn(box[b], powerup[c], destroyed[b]);
						}
			}
		}

		gm.EnemiesAlive(enemy[0], enemy[1], enemy[2], enemy[3]);
	}

	//------------------------------PANTALLA FINAL DE PARTIDA-------------------------------------

	system("cls");

	HANDLE  hConsole;
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (gm.GetWin())
	{
		SetConsoleTextAttribute(hConsole, 10);
		std::cout << "Felicidades, has derrotado a todos los enemigos.";
	}
	else
	{
		SetConsoleTextAttribute(hConsole, 12);
		std::cout << "Vaya, has muerto, mas suerte la proxima vez.";
	}
}