#include "stdafx.h"
#include "CppUnitTest.h"
#include"../source/dict.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Dicttest
{		
	TEST_CLASS(NativDict)
	{
	public:
		
		TEST_METHOD(put)
		{
			NativeDict<int>a;
			Assert::IsFalse(a.is_key("key1"));
			a.put("key1", 12);
			Assert::IsTrue(a.is_key("key1") && a.get("key1") == 12);
			a.put("key1", 32);
			Assert::IsTrue(a.is_key("key1") && a.get("key1") == 32);
			Assert::IsTrue(a.get("key12") == NULL);

		}
		TEST_METHOD(is_key)
		{
			NativeDict<int>a;
			Assert::IsFalse(a.is_key("key1"));
			a.put("key1", 12);
			Assert::IsTrue(a.is_key("key1"));
		}
		TEST_METHOD(get)
		{
			NativeDict<int>a;
			Assert::IsTrue(a.get("key12") == NULL);
			a.put("key1", 12);
			Assert::IsTrue((a.get("key1") != NULL)&&(a.get("key1")==12));
		}
		TEST_METHOD(operators)
		{
			NativeDict<int>a;
			a["key"] = 12;
			Assert::IsTrue(a.get("key") == 12);
			Assert::IsTrue(a["key1"] == NULL);
		}

	};
}