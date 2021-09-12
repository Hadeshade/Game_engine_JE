// Feito por Marco Antonio Nemetala Garcia
#include "GameObject.h"
#include "Component.h"

// Construtor
GameObject::GameObject()
{
    isDead = false;
}

// Destrutor
GameObject::~GameObject()
{
    // Percorrer o vetor componenets de traz para frente para excluir tudo dentro dele;
}

// Percorre o vetor de componentes chamando o Update(dt) dos mesmos
void GameObject::Update(float dt)
{
    //percorre o vetor de componentes chamando o Update(dt) dos mesmos
    for (std::vector<Component*>::size_type i = 0; i != components.size(); i++)
    {
        components[i]->Update(2.1);
    }
    
}

// Percorre o vetor de componenets chamando o Render dos mesmos.
void GameObject::Render()
{
    // Percorre o vetor de componenets chamando o Render dos mesmos.
    for (std::vector<Component*>::size_type i = 0; i != components.size(); i++)
    {
        components[i]->Render();
    }
}

// Retorna isDead
bool GameObject::IsDead()
{
    return isDead;
}

// Atribui verdadeiro a isDead
void GameObject::RequestDelete()
{
    isDead = true;
}

// Adiciona o componente ao vetor de componentes
void GameObject::AddComponent(Component* cpt)
{
    // Adiciona o componente ao vetor de componentes
    components.emplace_back(cpt);
}

// Remove o componente ao vetor de componentes
void GameObject::RemoveComponent(Component* cpt)
{
    // Remove o componente ao vetor de componentes 
    // TA TUDO ERRADOO
    // std::vector<Component*>::iterator pos = std::find(components.begin(), components.end(), cpt);
    // if (pos != components.end())
    // {
    //     components.erase(pos);
    // }
    // components.erase(std::remove(components.begin(), components.end(), cpt), components.end());
    
}

// Retorna um ponteiro para o componente do tipo solicitado que estiver adicionado nesse objeto. nullptr caso esse componente não exista. 
Component* GameObject::GetComponent(std::string type)
{
    // Retorna um ponteiro para o componente do tipo solicitado que estiver adicionado nesse objeto. nullptr caso esse componente não exista. 
}