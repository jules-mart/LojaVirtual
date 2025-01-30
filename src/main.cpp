#include <CustomLibraries.hpp>

int	main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "To initialize the program, you must provide the store`s name:" << std::endl;
        std::cout << "'./store <STORE_NAME>'" << std::endl;
        return 1;
    }

    system("clear");
    StoreSystem store(argv[1]);
    store.run();
}
