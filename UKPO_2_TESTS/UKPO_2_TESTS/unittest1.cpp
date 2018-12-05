#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include "TextParser.h"
#include <iostream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UKPO_tests_2
{
    TEST_CLASS(UnitTest1)
    {
    public:
        TEST_METHOD(TestMethod1)
        {
           std::string findString = "igla";
		   std::string textString = "stogigrastogstogaigstogstogiglstogstogiglastogiglastogukpo";
		   int expected = 39;

		   TextParser* test = new TextParser(findString, textString);
		   test -> cutString();
		   int real = test -> answer;

		   Assert::AreEqual(expected, real);
        }
        TEST_METHOD(TestMethod2)
        {
           std::string findString = "ig.a";
		   std::string textString = "stogigrastogstogaigstogstogiglstogstogiglastogiglastogukpo";
		   
		   int expected = 5;

		   TextParser* test = new TextParser(findString, textString);
		   test -> cutString();
		   int real = test -> answer;

		   Assert::AreEqual(expected, real);
        }
        TEST_METHOD(TestMethod3)
        {
           std::string findString = "ig+a";
		   std::string textString = "stogigrastogstogaigstogstogiglstogstogiglastogiglastogukpo";
		   int expected = 5;

		   TextParser* test = new TextParser(findString, textString);
		   test -> cutString();
		   int real = test -> answer;

		   Assert::AreEqual(expected, real);
        }
        TEST_METHOD(TestMethod4)
        {
           std::string findString = "iga";
		   std::string textString = "stogigrastogstogaigstogstogiglstogstogiglastogiglastogukpo";
		   int expected = -1;

		   TextParser* test = new TextParser(findString, textString);
		   test -> cutString();
		   int real = test -> answer;

		   Assert::AreEqual(expected, real);
        }
        TEST_METHOD(TestMethod5)
        {
           std::string findString = "ig.stog";
		   std::string textString = "stogigrastogstogaigstogstogiglstogstogiglastogiglastogukpo";
		   int expected = 28;

		   TextParser* test = new TextParser(findString, textString);
		   test -> cutString();
		   int real = test -> answer;

		   Assert::AreEqual(expected, real);
        }
        TEST_METHOD(TestMethod6)
        {
           std::string findString = "ig*stog";
		   std::string textString = "stogigrastogstogaigstogstogiglstogstogiglastogiglastogukpo";
		   int expected = 5;

		   TextParser* test = new TextParser(findString, textString);
		   test -> cutString();
		   int real = test -> answer;

		   Assert::AreEqual(expected, real);
        }
        TEST_METHOD(TestMethod7)
        {
           std::string findString = "stog*ig";
		   std::string textString = "stogigrastogstogaigstogstogiglstogstogiglastogiglastogukpo";
		   int expected = 1;

		   TextParser* test = new TextParser(findString, textString);
		   test -> cutString();
		   int real = test -> answer;

		   Assert::AreEqual(expected, real);
        }
        TEST_METHOD(TestMethod8)
        {
           std::string findString = "stog+ig";
		   std::string textString = "stogigrastogstogaigstogstogiglstogstogiglastogiglastogukpo";
		   int expected = 1;

		   TextParser* test = new TextParser(findString, textString);
		   test -> cutString();
		   int real = test -> answer;

		   Assert::AreEqual(expected, real);
        }
        TEST_METHOD(TestMethod9)
        {
           std::string findString = "stog.ig";
		   std::string textString = "stogigrastogstogaigstogstogiglstogstogiglastogiglastogukpo";
		   int expected = 13;

		   TextParser* test = new TextParser(findString, textString);
		   test -> cutString();
		   int real = test -> answer;

		   Assert::AreEqual(expected, real);
        }
        TEST_METHOD(TestMethod10)
        {
           std::string findString = ".tog";
		   std::string textString = "stogigrastogstogaigstogstogiglstogstogiglastogiglastogukpo";
		   int expected = 2;

		   TextParser* test = new TextParser(findString, textString);
		   test -> cutString();
		   int real = test -> answer;

		   Assert::AreEqual(expected, real);
        }
        TEST_METHOD(TestMethod11)
        {
           std::string findString = ".gra";
		   std::string textString = "stogigrastogstogaigstogstogiglstogstogiglastogiglastogukpo";
		   int expected = -1;

		   TextParser* test = new TextParser(findString, textString);
		   test -> cutString();
		   int real = test -> answer;

		   Assert::AreEqual(expected, real);
        }
		TEST_METHOD(TestMethod12)
        {
           std::string findString = ".gra";
		   std::string textString = "";
		   int expected = -1;

		   TextParser* test = new TextParser(findString, textString);
		   test -> cutString();
		   int real = test -> answer;

		   Assert::AreEqual(expected, real);
        }
		TEST_METHOD(TestMethod13)
        {
           std::string findString = "";
		   std::string textString = "stogigrastogstogaigstogstogiglstogstogiglastogiglastogukpo";
		   int expected = -1;

		   TextParser* test = new TextParser(findString, textString);
		   test -> cutString();
		   int real = test -> answer;

		   Assert::AreEqual(expected, real);
        }
    };
}