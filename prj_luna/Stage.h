#ifndef __STAGE_H
#define __STAGE_H


class Stage
{
public:
    Stage(class Application* a);
    virtual ~Stage();
    
    virtual void LoadStageData();
    virtual void UpdateStage();
    virtual void UnloadStageData();

    void ProcessInput(const struct InputState& state);
    // 派生先での入力処理 Override
    virtual void StageInput(const struct InputState& state);
    
    bool GetQuitStage(){ return isQuitStage; }
    
protected:
    class Application* app;
    
    bool isQuitStage; // trueになったら遷移する
};


#endif // __STAGE_H
