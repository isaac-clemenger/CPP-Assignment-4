// PHYS 30762 Programming in C++
// Assignment 4
// Isaac Clemenger 13/03/2024
// Practice special functions and operators in C++ classes
/* 
   Code that creates objects of the class particle, which contains the particle type, charge, rest mass and four momentum.
   Overloads the + operator such that the four momenta of the particles can be summed. Class also contains a function to find
   the dot product of the four momenta of two particles. Also contains constructors, and overloads the = operator, to make deep
   copies of objects, and to move objects. 
*/
// To complie paste in the terminal: C:/msys64/ucrt64/bin/g++ --std=c++17 -g assignment-4.cpp particle.cpp -o main.exe

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include"Particle.h"

// Initialise constants
const double electron_rest_mass{0.511}, muon_rest_mass{105.7}; // Masses in MeV

// Main program
int main()
{
  // Create the following particles: 
  // two electrons, four muons, one antielectron, one antimuon 
  // Use the parameterised constructor to do these
  std::vector<Particle> particles;
  try
  {
    // Try to create particles, any non-physical values will be caught by the catch statement
    Particle electron1("electron", -1, electron_rest_mass, rand(), rand(), rand(), rand());
    particles.push_back(electron1);
 
    Particle electron2("electron", -1, electron_rest_mass, rand(), rand(), rand(), rand());
    particles.push_back(electron2);

    Particle positron1("positron", +1, electron_rest_mass, rand(), rand(), rand(), rand());
    particles.push_back(positron1);
    
    Particle muon1("muon", -1, muon_rest_mass, rand(), rand(), rand(), rand());
    particles.push_back(muon1);
  
    Particle muon2("muon", -1, muon_rest_mass, rand(), rand(), rand(), rand());
    particles.push_back(muon2);

    Particle muon3("muon", -1, muon_rest_mass, rand(), rand(), rand(), rand());
    particles.push_back(muon3);
    
    Particle muon4("muon", -1, muon_rest_mass, rand(), rand(), rand(), rand());
    particles.push_back(muon4);

    Particle antimuon1("antimuon", +1, muon_rest_mass, rand(), rand(), rand(), rand());
    particles.push_back(antimuon1);
  
    // Print out the data from all the particles
    for (auto particle_it{particles.begin()}; particle_it < particles.end(); particle_it++)
    {
      particle_it->print_particle_data();
    }

    // Creating a break to make terminal easier to read
    std::cout<<"\n\n";
    // Sum the four-momenta of the two electrons 
    std::cout<<"Summing the four momenta of electron1 and electron2\n";
    std::vector<double> momenta_summed = electron1 + electron2;
    std::cout<<"P = (";
    for (auto sum_it{momenta_summed.begin()}; sum_it < momenta_summed.end(); sum_it++)
    {
      // Just formatting the output with commas 
      if (sum_it != momenta_summed.begin()) std::cout<<", ";
      std::cout<<*sum_it;
    }
    std::cout<<")\n";
    // Creating a break to make terminal easier to read
    std::cout<<"\n\n";

    // Do the dot product of the first two four-muons
    std::cout<<"The dot product of the four momenta of muon1 and muon2 is: ";
    double dot_product{muon1.four_dot_product(muon2)};
    std::cout<<dot_product<<"\n";
    // Creating a break to make terminal easier to read
    std::cout<<"\n\n";

    // Assignment operator of an electron to a new electron
    std::cout<<"Assigning electron1 to new electron\n";    
    Particle electron3;
    electron3 = electron1;
    electron1.print_particle_data();
    electron3.print_particle_data();
    // Creating a break to make terminal easier to read
    std::cout<<"\n\n";

    // Copy constructor of the first muon to a new muon
    std::cout<<"Copying muon1 to new muon\n";
    Particle muon5{muon1};
    muon1.print_particle_data();
    muon5.print_particle_data();
    // Creating a break to make terminal easier to read
    std::cout<<"\n\n";
    
    // Move the positron into another positron using the move constructor 
    std::cout<<"Moving positron1 to new positron\n";
    Particle positron2;
    positron2 = std::move(positron1);
    positron2.print_particle_data();
    // Creating a break to make terminal easier to read
    std::cout<<"\n\n";

    // Assign the antimuon to another antimuon using the move assignment
    std::cout<<"Moving antimoun1 to new antimuon\n";    
    Particle antimuon2{std::move(antimuon1)};
    antimuon2.print_particle_data();
    // Creating a break to make terminal easier to read
    std::cout<<"\n\n";
  } catch(...)
  {
    // If non physical energy is inputted, exit the program
    std::cout<<"Exiting program\n";
    return 1;
  }
  return 0;
}