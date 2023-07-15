#include "UfoEnemy.h"
#include "Application.h"
#include "Renderer.h"

UfoEnemy::UfoEnemy(Application* a)
    : EnemyActor(a)
{
    meshComp = std::make_unique<MeshComponent>(this);
    meshComp->SetMesh(GetApp()->GetRenderer()->GetMesh("Assets/moai.lwo"));
    meshComp->SetVisible(false);
    meshComp->SetToonRender(true, 1.04f);
}

void UfoEnemy::UpdateActor(float deltaTime)
{
    if(isDisp)
    {
        meshComp->SetVisible(true);
        auto v = GetPosition();
        SetPosition(Vector3(v.x, v.y, v.z-2));
        if(v.z < 0)
        {
            isDisp = false;
            meshComp->SetVisible(false);
        }
    }
}
