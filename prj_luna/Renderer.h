#pragma once

#include "Math.h"

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include <SDL2/SDL.h>


// ディレクショナルライト
struct DirectionalLight{
    Vector3 Direction;      // 向き
    Vector3 DiffuseColor;   // 色
    Vector3 SpecColor;      // 反射色
};


// 描画エンジン
class Renderer
{
public:
    // コンストラクタ
    Renderer();
    // デストラクタ
    ~Renderer();
      
    // 初期化
    bool Initialize(std::string title, float scWidth, float scHeight);
    // 描画（Applicationから呼ばれる）
    void Draw();
    // 終了
    void Shutdown();

    void SetClearColor(float r, float g, float b);


    // ビューマトリックスを設定する
    void SetViewMatrix(const Matrix4& view) { invView = viewMatrix = view; invView.Invert();}
    Matrix4 GetViewMatrix() const { return viewMatrix; }
    Matrix4 GetInvViewMatrix() const { return invView; }

    // スクリーンサイズのGtter
    float GetScreenWidth() const { return screenWidth; }
    float GetScreenHeight() const { return screenHeight; }
      
    
    // スプライトコンポーネント登録・削除
    void AddSprite(class SpriteComponent* sprite);
    void RemoveSprite(class SpriteComponent* sprite);
    // メッシュコンポーネント登録・削除
    void AddMeshComp(class MeshComponent* mesh);
    void RemoveMeshComp(class MeshComponent* mesh);
    // 背景メッシュコンポーネント登録・削除
    void AddBackGroudMeshComp(class MeshComponent* mesh);
    void RemoveBackGroudMeshComp(class MeshComponent* mesh);
    // パーティクルコンポーネント登録・削除
    void AddParticleComp(class ParticleComponent* part);
    void RemoveParticleComp(class ParticleComponent* part);
    // ビルボード登録・削除
    void AddBillboardComp(class BillboardComponent* billboard);
    void RemoveBillboardComp(class BillboardComponent* billboard);
    // デバッガーコンポーネント登録・削除
    void AddDebuggerComp(class DebuggerComponent* dbg);
    void RemoveDebuggerComp(class DebuggerComponent* dbg);
    
    
    // メッシュ登録
    class Mesh* GetMesh(const std::string& fileName);
    // テクスチャ登録
    class Texture* GetTexture(const std::string& fileName);


    // データ解放
    void UnloadData();
    
    // アンビエントライト設定
    void SetAmbientLight(const Vector3& ambient) { ambientLight = ambient; }
    DirectionalLight& GetDirectionalLight() { return dirLight; }
    
    
private:
    // ウィンドウタイトル
    std::string strTitle = "SDL2/OpenGL";
    // Windowハンドラ
    SDL_Window* window;
    // GLコンテキスト
    SDL_GLContext lpGL;

    // ビューマトリックス
    Matrix4 viewMatrix;
    Matrix4 invView;
    // プロジェクションマトリックス
    Matrix4 projectionMatrix;
    //スクリーンサイズ
    float screenWidth;
    float screenHeight;
    
    

    // メッシュ用シェーダー
    std::unique_ptr<class Shader> meshShader;
    std::unique_ptr<class Shader> meshShaderToon;
    std::unique_ptr<class Shader> backGroundShader;
    // スキンメッシュ用シェーダー
    std::unique_ptr<class Shader> skinnedShader;
    std::unique_ptr<class Shader> skinnedShaderToon;
    // スプライト用シェーダー
    std::unique_ptr<class Shader> spriteShader;
    // ビルボード用シェーダー
    std::unique_ptr<class Shader> billboardShader;
    // シェーダー一括ロード
    bool LoadShaders();

    // スプライト用ポリゴン（Billboardでも使う）
    class VertexArray* spriteVerts;
    // スプライト用ポリゴンの生成
    void CreateSpriteVerts();
    
    // Lightsingをシェーダーに送る
    void SetLightUniforms(class Shader* shader);
    
    // アセット
    std::unordered_map<std::string, class Texture*> textures;
    std::unordered_map<std::string, class Mesh*> meshes;

    // コンポーネント
    std::vector<class SpriteComponent*> spriteComps;
    std::vector<class MeshComponent*> meshComps;
    std::vector<class MeshComponent*> backGroudComps;
    std::vector<class SkeletalMeshComponent*> skeletalMeshes;
    std::vector<class ParticleComponent*> particleComps;
    std::vector<class BillboardComponent*> billboardComps;
    std::vector<class DebuggerComponent*> dbgComps;
    
    
    // ライト
    Vector3 ambientLight;
    DirectionalLight dirLight;
    



};

