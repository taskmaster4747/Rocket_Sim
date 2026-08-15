#include <iostream>
#include <cmath>
#include <fstream>

int main() {
     std::ofstream file("rocket_data.csv");
     file << "time,height\n";
    // Time
    double dt = 0.1;   // time step (seconds)
    double time = 0.0;

    // Rocket state
    double position = 0.0;   // height (meters)
    double velocity = 0.0;   // m/s

    // Constants
    double gravity = 9.81;   // m/s^2
    double mass = 1000.0;    // kg
    double thrust = 15000.0; // Newton

    // Fuel
    double fuel = 500.0;     // arbitrary units
    double burn_rate = 5.0;  // fuel per second

    std::cout << "Time\tHeight\tVelocity\n";

    while (position >= 0) {
        // Stop thrust if fuel is gone
        if (fuel <= 0) {
            thrust = 0;
        } else {
            fuel -= burn_rate * dt;
        }

        // Physics
        double acceleration = (thrust / mass) - gravity;

        velocity += acceleration * dt;
        position += velocity * dt;

        double drag = 0.5 * 0.1 * velocity * velocity;
        acceleration = (thrust - drag) / mass - gravity;  

        // Print values
        std::cout << time << "\t" << position << "\t" << velocity << "\n";

        // Update time
        time += dt;

        // Stop after 100 seconds (safety)
        if (time > 100) break;

        if (position <= 0 && time > 1) {
        std::cout << "Rocket crashed or landed!\n";
        break;
     }
     file << time << "," << position << "\n";
     }

     file.close();

    //std::ofstream file("Semple1data.csv");
   
    
    file << "time,height,velocity\n";
    
    file << time << "," << position << "," << velocity << "\n";
    
    return 0;
}