#ifndef __PLANEACTOR_H
#define __PLANEACTOR_H

#include "Actor.h"


// 飛行機
class PlaneActor : public Actor
{
public:
    PlaneActor(class Application* app);

    void ActorInput(const struct InputState& state) override;
    void UpdateActor(float deltaTime) override;

    void SetVisible(bool visible);
    
private:
    //  前フレームの場所
    Vector3 prevPos;
    
    // モーションID
    int animID;
    
    class SkeletalMeshComponent* meshComp;
    class MoveComponent* moveComp;
    class FollowCamera* cameraComp;
    
    
    // フィールド移動用
    void FieldMove(const struct InputState& state);
    // モーションを適用
    void ApplyMotion();
    
    // 動作可能=true 動作不可能=false
    bool isMovable;

};





#endif // __PLANEACTOR_H
