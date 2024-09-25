#include <iostream>
#include <cmath>
#include <vector>

double CalcdPhi(double dPhiTemp)
{
    double dPhi;

    if (dPhiTemp > 180.0)
    {
        dPhi = dPhiTemp - 360.0;
    }
    else if (dPhiTemp < -180.0)
    {
        dPhi = dPhiTemp + 360.0;
    }
    else
    {
        dPhi = dPhiTemp;
    }

    return dPhi;
}

// Function to find the angle closest to 180 degrees away from phi_N
double getPhi_e(double phi_N)
{
    std::vector<double> possible_angles = {-120, -60, 0, 60, 120, 180};

    // Calculate the target angle (180 degrees away from phi_N)
    double target_angle = CalcdPhi(phi_N + 180);

    // Find the closest possible angle
    double closest_angle = possible_angles[0];
    double min_diff = std::abs(CalcdPhi(target_angle - closest_angle));

    for (double angle : possible_angles)
    {
        double diff = std::abs(CalcdPhi(target_angle - angle));
        if (diff < min_diff)
        {
            min_diff = diff;
            closest_angle = angle;
        }
    }

    return closest_angle;
}