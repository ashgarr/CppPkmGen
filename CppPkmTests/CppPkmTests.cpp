#include "pch.h"
#include "CppUnitTest.h"
#include "../CppPkmGen/NumberGenerator.h"
#include "../CppPkmGen/Pokemon.h"
#include "../CppPkmGen/Trainer.h"
#include "../CppPkmGen/NumberGenerator.cpp"
#include "../CppPkmGen/Pokemon.cpp"
#include "../CppPkmGen/Trainer.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CppPkmTests
{
	TEST_CLASS(Shininess)
	{
	public:

		TEST_METHOD(CanGenerateShiny)
		{
			int counter = 0;
			int limit = 1000000;
			bool shinyFound = false;
			Trainer trainer = Trainer("Obama");

			while (!shinyFound && counter < limit)
			{
				Pokemon a = Pokemon(1);
				if (a.checkShiny(trainer.getTrainerID(), trainer.getSecretID(), true)) {
					shinyFound = true;
				}
			}

			Assert::AreEqual(true, shinyFound);
		}
	};
}
