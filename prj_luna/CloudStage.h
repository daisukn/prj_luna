#ifndef __CLOUDSTAGE_H
#define __CLOUDSTAGE_H

#include "Stage.h"
#include <memory>

class CloudStage : public Stage
{
private:
    std::unique_ptr<class PlaneActor> planeActor;
    std::unique_ptr<class DragonActor> dragonActor;
    float ang = 0.f;
public:
    CloudStage(class Application* a);
    ~CloudStage();
    
    virtual void LoadStageData() override;
    virtual void UnloadStageData() override;
    virtual void UpdateStage() override;
    
    virtual void StageInput(const struct InputState& state) override;
};


#endif // __CLOUDSTAGE_H
