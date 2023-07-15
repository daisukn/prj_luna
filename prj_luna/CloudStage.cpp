#include "CloudStage.h"
#include "Application.h"
#include "MeshComponent.h"
#include "Actor.h"
#include "Renderer.h"
#include "PlaneActor.h"
#include "DragonActor.h"
#include "BGCloudActor.h"
#include "UfoEnemy.h"

const int MAX_CLOUD = 20;
const int MAX_UFO = 20;

CloudStage::CloudStage(class Application* a)
    : Stage(a)
    , stageCounter(0)
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

    
    for(int i = 0; i < MAX_CLOUD; i++)
    {
        cloudActor.push_back( std::make_unique<BGCloudActor>(app) );
    }
    for(int i = 0;  i < MAX_UFO; i++)
    {
        ufoEnemy.push_back( std::make_unique<UfoEnemy>(app));
    }
    

    skyActor = std::make_unique<Actor>(app);
    skyActor->SetPosition(Vector3(0, 0, 500));
    Quaternion q(Vector3::UnitY, Math::ToRadians(180));
    skyActor->SetRotation(q);
    skyActor->SetScale(1);
    skyMesh = std::make_unique<MeshComponent>(skyActor.get());
    skyMesh->SetMesh(app->GetRenderer()->GetMesh("Assets/sky.lwo"));
    

    isQuitStage = false;
    
    app->GetRenderer()->SetClearColor(0.596f, 0.733f, 0.858f);
    //app->GetRenderer()->SetClearColor(0.05f, 0.01f, 0.258f);
    
}

void CloudStage::UnloadStageData()
{
}

void CloudStage::StageInput(const struct InputState &state)
{
    
}

void CloudStage::UpdateStage()
{
    stageCounter++;
    
    if(stageCounter % 20 == 0)
    {
        for(int i = 0; i < MAX_CLOUD; i++)
        {
            if(!cloudActor[i]->GetDisp())
            {
                cloudActor[i]->SetDisp(true);
                cloudActor[i]->SetPosition(Vector3(50, 0, 300));
                break;
            }
        }
    }
    
    if(stageCounter % 20 == 10)
    {
        for(int i = 0; i < MAX_CLOUD; i++)
        {
            if(!cloudActor[i]->GetDisp())
            {
                cloudActor[i]->SetDisp(true);
                cloudActor[i]->SetPosition(Vector3(-50, 0, 300));
                break;
            }
        }
    }
}
