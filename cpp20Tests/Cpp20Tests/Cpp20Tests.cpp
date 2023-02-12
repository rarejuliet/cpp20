#include "pch.h"
#include "../../math.h"
#include "../../string_utils.h"
//#include <memory>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Cpp20Tests {
	TEST_CLASS(string_utils)
	{
		TEST_METHOD(string_utils_remove_trailing_backslash) {
			std::string a = R"(C:\Temp\)";
			//if('\\'==a.at(a.size()-1)) {
			//	//remove it
			//	a = a.substr(0,a.size()-1);
			//}
			const std::string b = R"(C:\Temp)";
			//util::remove_trailing_backslash(
			const std::string c = util::remove_trailing_backslash(fs::path(a));
			Assert::AreNotEqual(a,b);
			Assert::AreEqual(b,c);
		}
	};
	TEST_CLASS(vfsTests)
	{
	public:
		std::filesystem::path test_dir = std::filesystem::temp_directory_path();
		std::filesystem::path new_dir = test_dir / "test_dir_from_vfs";
		std::unique_ptr<vfs::real_fs> vfs;
		TEST_METHOD_INITIALIZE(vfs_init) {
			Logger::WriteMessage("Creating a smart pointer to a vfs instance at ");
			Logger::WriteMessage(test_dir.c_str());
			Logger::WriteMessage("...");
			vfs = std::make_unique<vfs::real_fs>(test_dir.string());
			if(vfs->mkdir(new_dir)) {
				vfs->chdir(new_dir);
				Logger::WriteMessage("Done!\n");
				Logger::WriteMessage(new_dir.c_str());
				Logger::WriteMessage(" is now the current directory.\n");
			}
		}
		TEST_METHOD_CLEANUP(vfs_teardown) {
			Logger::WriteMessage("In teardown.");
			Logger::WriteMessage("Closing the current directory...");
			vfs->closedir();
			Logger::WriteMessage("Done!\n");
		}

		/// <summary>
		/// Tests the chdir function of the vfs. 
		/// </summary>
		BEGIN_TEST_METHOD_ATTRIBUTE(vfs_chdir)
			TEST_OWNER(L"Adam Choate")
			TEST_PRIORITY(1)
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(vfs_chdir)
		{
			vfs->chdir(test_dir);
			fs::path p{vfs->cwd()};
			std::string s = p.string();//util::remove_trailing_backslash(p);
			Assert::AreEqual(p.string(),s);
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(vfs_mkdir)
			TEST_OWNER(L"Adam Choate")
			TEST_PRIORITY(2)
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(vfs_mkdir)
		{
			if(vfs->mkdir(new_dir)) {
				Logger::WriteMessage(L"mkdir(");
				Logger::WriteMessage(new_dir.c_str());
				Logger::WriteMessage(L") was successful.\n:");
				Assert::AreEqual(std::filesystem::exists(new_dir), true);
			}
		}

		BEGIN_TEST_METHOD_ATTRIBUTE(vfs_chdir2)
			TEST_OWNER(L"Adam Choate")
			TEST_PRIORITY(3)
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(vfs_chdir2) {
			try {
				vfs->chdir(new_dir);
				Logger::WriteMessage(L"\nNew current directory is: ");
				Logger::WriteMessage(vfs->cwd().c_str());
				Logger::WriteMessage(L"\n");
				std::filesystem::path cd = vfs->cwd();

				Assert::AreEqual(new_dir.c_str() ,(cd).c_str());
			} catch (std::exception& e) {
				Logger::WriteMessage(L"Caught an exception: ");
				Logger::WriteMessage(e.what());
			} catch (...) {
				Logger::WriteMessage(L"Caught an unknown exception!");
				auto e = std::make_unique<std::exception_ptr>(std::current_exception());
				Logger::WriteMessage(typeid(e).name());
				Logger::WriteMessage(L"\n");
				Logger::WriteMessage(typeid(e).raw_name());
				Logger::WriteMessage(L"\n");
			}
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(vfs_readdir_recurse)
			TEST_OWNER(L"Adam Choate")
			TEST_PRIORITY(4)
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(vfs_readdir_recurse) {
			vfs->chdir(new_dir);
			auto dirs = vfs->readdir_recurse();
			Logger::WriteMessage("Contents of directory: ");
			Logger::WriteMessage(vfs->cwd().c_str());
			Logger::WriteMessage("\n");
			for (const auto & dir : dirs)
			{
				Logger::WriteMessage(dir.c_str());
				Logger::WriteMessage("\n");
			}
		}
		BEGIN_TEST_METHOD_ATTRIBUTE(vfs_unlink)
			TEST_OWNER(L"Adam Choate")
			TEST_PRIORITY(5)
		END_TEST_METHOD_ATTRIBUTE()
		TEST_METHOD(vfs_unlink)
		{
			try {
				std::filesystem::path path = test_dir;
				if(vfs->cwd() == test_dir)
					vfs->chdir(test_dir.parent_path());
				if(vfs->unlink(path))
					assert(!std::filesystem::exists(path));
					if(std::filesystem::exists(path))
						Logger::WriteMessage(L"unlink() was UNSUCCESSFUL.");
					else
						Logger::WriteMessage(L"unlink() was SUCCESSFUL\n");

			} catch (std::exception& e) {
				Logger::WriteMessage(L"Caught an exception: ");
				Logger::WriteMessage(e.what());
			} catch (...) {
				Logger::WriteMessage(L"Caught an unknown exception!");
				auto e = std::make_unique<std::exception_ptr>(std::current_exception());
				Logger::WriteMessage(typeid(e).name());
				Logger::WriteMessage(L"\n");
				Logger::WriteMessage(typeid(e).raw_name());
				Logger::WriteMessage(L"\n");
			}
		}
	};
	TEST_CLASS(math_Fibonacci) {

		TEST_METHOD_INITIALIZE(fibonacci_sanity_check) {
			static_assert(math::Fibonacci::iterative(3) == math::Fibonacci::recursive(3));
			static_assert(math::Fibonacci::recursive(9) == math::Fibonacci::iterative(9));
		}
		TEST_METHOD(fibonacci) {
			Assert::AreEqual(math::Fibonacci::recursive(5),math::Fibonacci::iterative(5));
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
			Logger::WriteMessage(L"\n");
			Logger::WriteMessage(L"It took the recursive function [");
			auto difference = t.elapsed - t2.elapsed;
			Logger::WriteMessage(util::to_str(difference).c_str()); 
			Logger::WriteMessage(L"] ns longer than the iterative one.");
			Logger::WriteMessage(L"\n");
			Assert::IsFalse(t.elapsed < t2.elapsed);
		}
	};
}
