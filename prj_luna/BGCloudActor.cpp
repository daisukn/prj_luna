#include "BGCloudActor.h"
#include "Application.h"
#include "Renderer.h"


BGCloudActor::BGCloudActor(Application* a)
    : Actor(a)
    , isDisp(false)
{
    cloudBillboard = std::make_unique<BillboardComponent>(this);
    cloudBillboard->SetTexture(GetApp()->GetRenderer()->GetTexture("Assets/Textures/cloud_1.png"));
//    cloudBillboard->SetTexture(GetApp()->GetRenderer()->GetTexture("Assets/Textures/moku.png"));
}

void BGCloudActor::UpdateActor(float deltaTime)
{
    if(isDisp)
    {
        cloudBillboard->SetVisible(true);
        auto v = GetPosition();
        SetPosition(Vector3(v.x, v.y, v.z-3));
        if(v.z < 0)
        {
            isDisp = false;
            cloudBillboard->SetVisible(false);
        }
    }
}
