#pragma once
#include <stdexcept> 
/*          __             __ 
 *    ___  / /  ___ ____  / /_
 *   / _ \/ _ \/ _ `/ _ \/ __/
 *  / .__/_//_/\_,_/_//_/\__/ 
 * /_/                        
 */

class VecEmpty : public std::exception {
    public: 
        const char* what() const noexcept override {
            return "Vector is empty";
        }
};

class VecOOB : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Index out of bounds";
        }
};
