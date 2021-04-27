#include "puzzle.h"
#include "solver.h"
#include "logger.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <thread>
#include <algorithm>  // std::sort
#include <mutex>

int main(int argc, char* argv[]) {

    std::string par1 = std::string(argv[1]);
    
    int NUM_THREADS;
    try {
        NUM_THREADS = std::stoi(par1);
    }
    catch (std::exception& e) {
        std::cerr << "cant read threads " << par1 << ": " << e.what() << '\n';
        exit(-1);
    }
    

    // Load the puzzles
    std::vector<Puzzle> puzzles;
    for(int i=1; i<argc; ++i) {
        try {
            std::string filename = std::string{argv[i]};
            std::ifstream ifs{filename};
            puzzles.push_back(Puzzle{filename, ifs});
        } catch(std::exception& e) {
            std::cerr << "Unable to open " << argv[i] << ": " 
                      << e.what() << std::endl;
        }
    }
    
    // Exit if one or more puzzles failed to load
    if((argc-1) != puzzles.size()) exit(-1);     
    
    
    // ----- All data loaded -----
    
    
    // Capture the solutions in a vector 
    std::vector<Solution> solutions;
    
    std::vector<std::thread*> threads;
    std::mutex mute;
    
    int puzzles_size=puzzles.size();
    const int puzzlesPerThread = 1;
    int first = 0;
    int last = puzzlesPerThread - 1;
    
    
    for(int i=0; i<NUM_THREADS; ++i){
        if(i==puzzles.size())
            break;
        
        threads.push_back(new std::thread{ [&, first, last] 
        {
            for (int j = first; j<=last; j++) {
                if (j>=puzzles.size()) {
                    break;
                    }
                    
                Puzzle& puzzle = puzzles.at(j);
                Solver solver{puzzle};
                
                for (std::string word : puzzle ) {
                    Solution s = solver.solve(word);
                    mute.lock();
                    solutions.push_back(s);
                    mute.unlock();
                  }
            }
        }   
   });
   
   }
    for(std::thread* t : threads) {
        t->join();
    }
    
    std::sort(solutions.begin(), solutions.end());
    for(Solution& s : solutions) std::cout << s << std::endl;
}
    
