#include "stdafx.h"
#include "CppUnitTest.h"
#include "../TextGame/Player.h"
#include <assert.h> 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Tests
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
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

	};
}