// CasingManager.cpp
#include "CasingManager.h"

void CasingManager::update(float deltaTime)
{
    idsToDelete.clear();
    for (auto& pair : casings)
    {
        pair.second.lifetime -= deltaTime;
        if (pair.second.lifetime <= 0)  
        {
            idsToDelete.push_back(pair.first);
            std::cout << "Casing Deleted: " << pair.first << std::endl;
        }
    }

    for (int id : idsToDelete)
    {
        casings.erase(id);
    }
}

void CasingManager::createCasing(float x, float y, float z)
{
    casings[nextId] = BulletCasing(nextId, x, y, z, 10.0f); // Assuming 30.0f as the default lifetime
    std::cout << "Casing Created: " << nextId << std::endl;
    nextId++;
}