#include "pch.h"
#include "../../math.h"
#include "../../string_utils.h"
//#include <memory>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Cpp20Tests
{
	TEST_CLASS(vfsTests)
	{
	public:
		std::filesystem::path test_dir = R"(C:\Temp)";
		std::filesystem::path new_dir = test_dir / "test_dir_from_vfs";
		std::unique_ptr<vfs::real_fs> vfs;
		TEST_METHOD_INITIALIZE(vfs_init) {
			Logger::WriteMessage("Creating a smart pointer to a vfs instance...");
			vfs = std::make_unique<vfs::real_fs>(test_dir.string());
			Logger::WriteMessage("Done!\n");
		}
		TEST_METHOD_CLEANUP(vfs_teardown) {
			Logger::WriteMessage("In teardown.");
			Logger::WriteMessage("Closing the current directory...");
			vfs->closedir();
			Logger::WriteMessage("Done!\n");
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(vfs_chdir)
			TEST_OWNER(L"Adam Choate")
			TEST_PRIORITY(1)
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(vfs_chdir)
		{
			bool success = vfs->chdir(test_dir);
			Assert::AreEqual(success,true);
			//if( success )
			//	Logger::WriteMessage(L"chdir() was successful.\n");
			//	//TODO: finish this test.
			//Logger::WriteMessage("Current directory is now: ");
			//Logger::WriteMessage(vfs->cwd().c_str());
			//Logger::WriteMessage("\n");
			//std::filesystem::path cd = vfs->cwd();
			//Assert::AreEqual(new_dir.string(), cd.string());
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(vfs_mkdir)
			TEST_OWNER(L"Adam Choate")
			TEST_PRIORITY(2)
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(vfs_mkdir)
		{
			//const std::filesystem::path dirname = test_dir / "test_dir_from_vfs";
			if(vfs->mkdir(new_dir))
				Logger::WriteMessage("mkdir() was successfull.\n:");
			Assert::AreEqual(std::filesystem::exists(new_dir), true);
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(vfs_chdir2)
			TEST_OWNER(L"Adam Choate")
			TEST_PRIORITY(3)
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(vfs_chdir2) {
			bool success = vfs->chdir(test_dir);
			if( success )
				Logger::WriteMessage(L"chdir() was successful.\n");
				//TODO: finish this test.
			Logger::WriteMessage("Current directory is now: ");
			Logger::WriteMessage(vfs->cwd().c_str());
			Logger::WriteMessage("\n");
			std::filesystem::path cd = vfs->cwd();
			Assert::AreEqual(test_dir.string(), cd.string());
			//bool success = vfs->chdir(new_dir);
			//if(success)
			//{
			//	Logger::WriteMessage("chdir(");
			//	Logger::WriteMessage(new_dir.c_str());
			//	Logger::WriteMessage(") SUCCEEDED\n");
			//}
			//Assert::AreEqual(new_dir.c_str(),vfs->cwd().c_str());
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(vfs_readdir_recurse)
			TEST_OWNER(L"Adam Choate")
			TEST_PRIORITY(4)
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(vfs_readdir_recurse)
		{
			vfs->chdir(new_dir);
			auto dirs = vfs->readdir_recurse();
			Logger::WriteMessage("Contents of directory: ");
			Logger::WriteMessage(vfs->cwd().c_str());
			for (const auto & dir : dirs)
			{
			 	Logger::WriteMessage(dir.c_str());
			}
			vfs->chdir("/");
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(vfs_unlink)
			TEST_OWNER(L"Adam Choate")
			TEST_PRIORITY(5)
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(vfs_unlink)
		{
			try {
				std::filesystem::path path = test_dir / "test_dir_from_vfs";
				if(vfs->unlink(path))
					if(std::filesystem::exists(path))
						Logger::WriteMessage("unlink() was UNSUCCESSFUL.");
					else
						Logger::WriteMessage("unlink() was SUCCESSFUL");
			} catch (...) {
				Logger::WriteMessage("Caught an exception: ");
			}
		}
	};
	TEST_CLASS(math_Fibonacci) {

		TEST_METHOD_INITIALIZE(fibonacci_sanity_check) {
			static_assert(math::Fibonacci::iterative(3) == math::Fibonacci::recursive(3));
			static_assert(math::Fibonacci::recursive(9) == math::Fibonacci::iterative(9));
		}
		TEST_METHOD(benchmark) {
			uint64_t input {0};

			Benchmark::test t{};
			std::vector<uint64_t> fibs{};
			for(uint64_t i=0; i< math::Fibonacci::MAX_FIBONACCI / 3; ++i)	{
				fibs.push_back(math::Fibonacci::recursive(i));
			}
			t.stop();
//			std::cout << "Elapsed time was: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t.elapsed) << "\n";
			Logger::WriteMessage("Elapsed time for recursive function was: ");
			auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(t.elapsed);
			Logger::WriteMessage(util::to_str(elapsed).c_str());
			fibs.clear();
			Benchmark::test t2{};
			for(uint64_t i=0; i< math::Fibonacci::MAX_FIBONACCI / 3; ++i)	{
				fibs.push_back(math::Fibonacci::iterative(i));
			}
			t2.stop();
			Logger::WriteMessage("\nElapsed time for iterative function was: ");
			elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(t2.elapsed);
			Logger::WriteMessage(util::to_str(elapsed).c_str());
			Logger::WriteMessage("\n");
			Logger::WriteMessage("It took the recursive function [");
			auto difference = t.elapsed - t2.elapsed;
			Logger::WriteMessage(util::to_str(difference).c_str()); 
			Logger::WriteMessage("] ns longer than the iterative one.");
			Logger::WriteMessage("\n");
			Assert::IsFalse(t.elapsed < t2.elapsed);
		}
	};
}
