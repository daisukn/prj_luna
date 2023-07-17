#include "MoaiEnemy.h"
#include "Application.h"
#include "Renderer.h"

MoaiEnemy::MoaiEnemy(Application* a)
    : EnemyActor(a)
{
    meshComp = std::make_unique<MeshComponent>(this);
    meshComp->SetMesh(GetApp()->GetRenderer()->GetMesh("Assets/moai.lwo"));
    meshComp->SetVisible(false);
    meshComp->SetToonRender(true, 1.04f);
//    SetScale(0.1f);
}

void MoaiEnemy::UpdateActor(float deltaTime)
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
