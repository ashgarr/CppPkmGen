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

		TEST_METHOD(ShinyIsAccurate)
		{
            Trainer trainer = Trainer("name");

            for (int i = 0; i < 40; i++)
            {
                bool shinyFound7 = false;
                bool shinyFound = false;
                while (!shinyFound7)
                {
                    Pokemon a = Pokemon(1);
                    if (a.checkShiny(trainer.getTrainerID(), trainer.getSecretID(), true))
                    {
                        shinyFound7 = true;
                        int shinyVal = a.getShinyVal(trainer.getTrainerID(), trainer.getSecretID());
                        bool valid = (shinyVal < 16) && (shinyVal >= 0);
                        Assert::IsTrue(valid, L"shiny value (gen 7) is out of range");
                    }
                }

                while (!shinyFound)
                {
                    Pokemon a = Pokemon(1);
                    if (a.checkShiny(trainer.getTrainerID(), trainer.getSecretID(), false))
                    {
                        shinyFound = true;
                        int shinyVal = a.getShinyVal(trainer.getTrainerID(), trainer.getSecretID());
                        bool valid = (shinyVal < 8) && (shinyVal >= 0);
                        Assert::IsTrue(valid, L"shiny value (NOT gen 7) is out of range");
                    }
                }
            }
		}
	};
}
