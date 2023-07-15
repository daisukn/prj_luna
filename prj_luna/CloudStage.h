#ifndef __CLOUDSTAGE_H
#define __CLOUDSTAGE_H

#include "Stage.h"

class CloudStage : public Stage
{
private:
    class Actor* cloudActor;
    class Actor* dragonActor;
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
