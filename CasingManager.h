// CasingManager.h
#ifndef CASINGMANAGER_H
#define CASINGMANAGER_H

#include <iostream>
#include <map>
#include <vector>
#include "BulletCasing.h"
#include <unordered_map>

class CasingManager
{
private:
    std::unordered_map<int, BulletCasing> casings;
    std::vector<int> idsToDelete;
    int nextId = 0;

public:
    void update(float deltaTime);
    void createCasing(float x, float y, float z);
};

#endif // CASINGMANAGER_H