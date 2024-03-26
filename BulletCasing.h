// BulletCasing.h
#ifndef BULLETCASING_H
#define BULLETCASING_H

class BulletCasing
{
public:
    int id;
    float posX, posY, posZ;
    float lifetime;

    BulletCasing() : id(0), posX(0.0f), posY(0.0f), posZ(0.0f), lifetime(0.0f) {}

    BulletCasing(int id, float x, float y, float z, float time);
};

#endif // BULLETCASING_H