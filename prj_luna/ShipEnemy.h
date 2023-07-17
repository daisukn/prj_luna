#ifndef __SHIPENEMY_H
#define __SHIPENEMY_H

#include "EnemyActor.h"

class ShipEnemy : public EnemyActor
{
public:
    ShipEnemy(class Application* a);
    void UpdateActor(float deltaTime) override;
private:
    std::unique_ptr<class SkeletalMeshComponent> skComp;
};



#endif // __SHIPENEMY_H


