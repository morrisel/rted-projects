" The compile with using requirements flags
g++ *.cpp -Wall -Wextra -Weffc++ -std=c++14 -pedantic -o program

" The improovement compile with the extra additional flags
g++ -std=c++14 -Wall -g -O0 -pedantic -std=c++14 -Wall -Wextra -Weffc++ -Wconversion -o out_program *.cpp
