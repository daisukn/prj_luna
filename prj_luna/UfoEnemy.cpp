#include "UfoEnemy.h"
#include "Application.h"
#include "Renderer.h"

UfoEenemy::UfoEenemy(Application* a)
    : EnemyActor(a)
{
    meshComp = std::make_unique<MeshComponent>(this);
    meshComp->SetMesh(GetApp()->GetRenderer()->GetMesh("Assets/ufo.lwo"));
}
