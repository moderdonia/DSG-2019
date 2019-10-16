#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TextGame/Player.h"
#include <assert.h> 
#include "../TextGame/World.h"
#include "../TextGame/GameLogic.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{		
	TEST_CLASS(UnitTest1)
	{

	public:
		TEST_METHOD(ganar)
		{
			
			World world;
			world.moneda1();
			Assert::AreEqual(1, world.getWinner());
			world.moneda2();
			Assert::AreEqual(0, world.getWinner());
			world.moneda2();
			Assert::AreEqual(2, world.getWinner());
		}
		TEST_METHOD(catarPared)
		{
			World world;
			world.createMaze(5,5);
			string aux = world.getMaze();
			string aux2 = "";
			Assert::AreEqual(aux , aux2);
		}
		TEST_METHOD(catarMoneda)
		{
			// TODO: Your test code here
		}
		TEST_METHOD(catarPersonaje)
		{
			// TODO: Your test code here
		}
		TEST_METHOD(TestMethod1)
		{
			

		}
		TEST_METHOD(leerFile)
		{
			
		}
		TEST_METHOD(testPlayer)
		{
			Player player1;
			player1.setPosition(10, 10);

			player1.moveDown();
			Assert::AreEqual(player1.getY(), 11);
			Assert::AreNotEqual(player1.getX(), 11);

			player1.moveLeft();
			Assert::AreEqual(player1.getX(), 9);

			player1.moveRight();
			Assert::AreEqual(player1.getX(), 10);

			player1.moveUp();
			Assert::AreEqual(player1.getY(), 10);

			Assert::AreEqual(player1.getcoin(), 0);
			player1.addcoin();
			Assert::AreEqual(player1.getcoin(), 1);

		}
		TEST_METHOD(testSetPosition)
		{
			Player player1;
			player1.setPosition(10, 10);
			Assert::AreEqual(player1.getX(), 10);
			Assert::AreEqual(player1.getY(), 10);

		}
		TEST_METHOD(moveRight)
		{
			Player player1;
			player1.setPosition(10, 10);
			player1.moveRight();
			Assert::AreEqual(player1.getX(), 11);
		}
		TEST_METHOD(moveLeft)
		{
			Player player1;
			player1.setPosition(10, 10);
			player1.moveLeft();
			Assert::AreEqual(player1.getX(), 9);
		}
		TEST_METHOD(moveDown)
		{
			Player player1;
			player1.setPosition(10, 10);
			player1.moveDown();
			Assert::AreEqual(player1.getY(), 11);
		}
		TEST_METHOD(moveUp)
		{
			Player player1;
			player1.setPosition(10, 10);
			player1.moveUp();
			Assert::AreEqual(player1.getY(), 9);
		}
		TEST_METHOD(addCoin)
		{
			Player player1;
			Assert::AreEqual(player1.getcoin(), 0);
			player1.addcoin();
			Assert::AreEqual(player1.getcoin(), 1);
		}
	};
}