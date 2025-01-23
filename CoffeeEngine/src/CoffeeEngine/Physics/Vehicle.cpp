#include "Vehicle.h"
#include <CoffeeEngine/Scene/Components.h>

namespace Coffee
{

    Vehicle::Vehicle(double mass, double initialX, double initialY)
        : mass(mass), positionX(initialX), positionY(initialY), velocityX(0.0), velocityY(0.0), accelerationX(0.0),
          accelerationY(0.0), forceX(0.0), forceY(0.0)
    {
    }

    // ���³���״̬
    void Vehicle::update(float dt)
    {
        // velocityX += accelerationX * deltaTime; // �����ٶ�
        // velocityY += accelerationY * deltaTime;

        // positionX += velocityX * deltaTime; // ����λ��
        // positionY += velocityY * deltaTime;

        selectedEntity = m_SceneTreePanel.GetSelectedEntity();
        if (selectedEntity)
        {
            // m_SceneTreePanel.GetSelectedEntity().GetComponent<TransformComponent>().Position.y = 100;
            COFFEE_CORE_WARN("Tag: {0}", selectedEntity.GetComponent<TransformComponent>().Position.x);
            selectedEntity.GetComponent<TransformComponent>().Position.x = 10;
        }
    }

    void Vehicle::OnEvent(Coffee::Event& event)
    {

        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<KeyPressedEvent>(COFFEE_BIND_EVENT_FN(Vehicle::OnKeyPressed));
    }

    bool Vehicle::OnKeyPressed(KeyPressedEvent& event)
    {
        /*if (event.IsRepeat() > 0)
            return false;*/

        if (selectedEntity)
        {
             const float moveSpeed = 1.0f; // �ƶ��ٶ�
             auto& position = selectedEntity.GetComponent<TransformComponent>().Position;

            if (selectedEntity.GetComponent<TagComponent>().Tag == "FINAL_MODEL_74.fbx")
            {
                switch (event.GetKeyCode())
                {
                case Coffee::Key::W:
                    position.z += moveSpeed; // ǰ��
                    break;
                case Coffee::Key::S:
                     position.z -= moveSpeed; // ����
                    break;
                case Coffee::Key::A:
                     position.x += moveSpeed; // ����
                    break;
                case Coffee::Key::D:
                     position.x -= moveSpeed; // ����
                    break;
                default:
                    return false;
                }
            }
        }
        return true;
    }

    // ��ȡ X ��λ��
    double Vehicle::getPositionX() const
    {
        return positionX;
    }

    // ��ȡ Y ��λ��
    double Vehicle::getPositionY() const
    {
        return positionY;
    }

    // ��ȡ X ���ٶ�
    double Vehicle::getVelocityX() const
    {
        return velocityX;
    }

    // ��ȡ Y ���ٶ�
    double Vehicle::getVelocityY() const
    {
        return velocityY;
    }

    void Vehicle::setEntity(Entity entity)
    {
        selectedEntity = entity;
    }

    Entity Vehicle::getEntity()
    {
        if (selectedEntity)
        {
            // printf("b");
        }

        return selectedEntity;
    }

} // namespace Coffee