#include <cstdio>
#include <cstring>
#include <cassert>
#include "tests/tests.h"

static constexpr size_t MaxNameLength = 16;

int main()
{
	static constexpr size_t TestCount = 1;
	static const std::unique_ptr<Test> Tests[TestCount] = {
			TestMatrix::Create(),
	};

	size_t index = 0;
	for(const auto &test : Tests) {
		const char *const name = test->name();
		const size_t nameLength = strlen(name);

		assert(nameLength <= MaxNameLength);

		char nameBuffer[MaxNameLength + 1] = {};
		memset(nameBuffer, ' ', MaxNameLength);
		strncpy(nameBuffer, name, nameLength);

		printf("Running test [%3zu] out of [%3zu] [%s] : ", index, TestCount, nameBuffer);

		try {
			test->execute();
		}
		catch(std::exception &exception) {
			printf("Failed\nReason: %s\n", exception.what());
			return EXIT_FAILURE;
		}

		printf("Success\n");

		++index;
	}

	return 0;
}
