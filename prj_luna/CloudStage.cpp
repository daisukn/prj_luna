#include "CloudStage.h"
#include "Application.h"
#include "MeshComponent.h"
#include "Actor.h"
#include "Renderer.h"
#include "PlaneActor.h"
#include "DragonActor.h"


CloudStage::CloudStage(class Application* a)
    : Stage(a)
{
    LoadStageData();
    
}

CloudStage::~CloudStage()
{
    UnloadStageData();
}


void CloudStage::LoadStageData()
{
    
    planeActor = std::make_unique<PlaneActor>(app);
    planeActor->SetPosition(Vector3(0, 0, 30));

    dragonActor = std::make_unique<DragonActor>(app);
    dragonActor->SetPosition(Vector3(0, 0, 100));



    isQuitStage = false;
    
    //app->GetRenderer()->SetClearColor(0.596f, 0.733f, 0.858f);
    app->GetRenderer()->SetClearColor(0.05f, 0.01f, 0.258f);
    
}

void CloudStage::UnloadStageData()
{
}

void CloudStage::StageInput(const struct InputState &state)
{
    
}

void CloudStage::UpdateStage()
{


}
