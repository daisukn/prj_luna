#ifndef __MOAIENEMY_H
#define __MOAIENEMY_H

#include "EnemyActor.h"

class MoaiEnemy : public EnemyActor
{
public:
    MoaiEnemy(class Application* a);
    void UpdateActor(float deltaTime) override;
};



#endif // __MOAIENEMY_H

