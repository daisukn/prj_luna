#ifndef __TITLESTAGE_H
#define __TITLESTAGE_H

#include "Stage.h"

class TitleStage : public Stage
{
    class Actor* titleActor;
    class MeshComponent* mc;
public:
    TitleStage(class Application* a);
    ~TitleStage();
    
    virtual void LoadStageData() override;
    virtual void UnloadStageData() override;
    virtual void UpdateStage() override;
    
    virtual void StageInput(const struct InputState& state) override;
};


#endif // __TITLESTAGE_H
