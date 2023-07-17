#ifndef __UFOACTOR_H
#define __UFOACTOR_H

#include "Actor.h"
#include "MeshComponent.h"
#include "MoveComponent.h"
#include "FollowCamera.h"
#include "ColliderComponent.h"
#include <memory>


// 敵の基底クラス
class EnemyActor : public Actor
{
public:
    EnemyActor(class Application* a);

    void UpdateActor(float deltaTime) override;

    //void SetVisible(bool visible);
    //bool GetVisible() const { return isVisible; }
    
    bool GetDisp() const { return isDisp; }
    void SetDisp(bool b) { isDisp = b; }
    
protected:
    std::unique_ptr<class MeshComponent> meshComp;
    std::unique_ptr<class ColliderComponent> collComp;
    bool isDisp;

};






#endif // __UFOACTOR_H
