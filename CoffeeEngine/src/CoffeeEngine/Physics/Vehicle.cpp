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

       // ���ݰ�������ת������
        if (moveLeft)
        {
            turnInput = 1.0f;
        }
        else if (moveRight)
        {
            turnInput = -1.0f;
        }
        else
        {
            turnInput = 0.0f; // ������ʱ����
        }

        // ����ת���ٶ�
        float turnFactor = glm::clamp(speed / maxSpeed, 0.2f, 1.0f); // �ٶȶ�ת���Ӱ�죨��� 10% ת��������
        currentTurnSpeed = maxTurnSpeed * turnFactor * turnInput;

        // ���·���ǣ����������ƶ�ʱ��
        if (glm::abs(speed) > 0.1f)
        { // ���һ���ٶ���ֵ�����⾲ֹʱת��
            rotation += currentTurnSpeed * dt;
        }

        // ������ٺͼ���
        if (moveFront)
        {
            speed += acceleration * dt;
            if (speed > maxSpeed)
            {
                speed = maxSpeed; // ��������ٶ�
            }
        }
        else if (moveBack)
        {
            speed -= acceleration * dt;
            if (speed < -maxSpeed / 2.0f)
            { // �����ٶ�����Ϊ����ٶȵ�һ��
                speed = -maxSpeed / 2.0f;
            }
        }
        else
        {
            // ���û�а�����Ӧ���������ٶ�������Ϊ 0��
            if (speed > 0)
            {
                speed -= drag * dt;
                if (speed < 0)
                    speed = 0;
            }
            else if (speed < 0)
            {
                speed += drag * dt;
                if (speed > 0)
                    speed = 0;
            }
        }

        // �����ٶ�����
        float radians = glm::radians(rotation); // ���Ƕ�תΪ����
        glm::vec3 velocity = glm::vec3(std::sin(radians), 0.0f, std::cos(radians)) * speed;

        if (selectedEntity)
        {
            auto& transform = selectedEntity.GetComponent<TransformComponent>();
            // ����ʵ���λ��
            transform.Position += velocity * dt;
            if (glm::abs(speed) > 0.1f)
            { // ���⾲ֹʱ�ı���ת
                transform.Rotation.y = rotation;
            }
        }
    }

    void Vehicle::OnEvent(Coffee::Event& event)
    {

        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<KeyPressedEvent>(COFFEE_BIND_EVENT_FN(Vehicle::OnKeyPressed));
        dispatcher.Dispatch<KeyReleasedEvent>(COFFEE_BIND_EVENT_FN(Vehicle::OnKeyRelease));
    }

    bool Vehicle::OnKeyPressed(KeyPressedEvent& event)
    {
        if (event.IsRepeat() > 0)
            return false;

        if (selectedEntity)
        {
            const float moveSpeed = 1.0f; // �ƶ��ٶ�
            auto& position = selectedEntity.GetComponent<TransformComponent>().Position;

            if (selectedEntity.GetComponent<TagComponent>().Tag == "FINAL_MODEL_74.fbx")
            {

                if (event.GetKeyCode() == Coffee::Key::W)
                {
                    moveFront = true;
                }

                switch (event.GetKeyCode())
                {
                case Coffee::Key::W:
                    moveFront = true;
                    break;
                case Coffee::Key::S:
                    moveBack = true;
                    break;
                case Coffee::Key::A:
                    moveLeft = true;
                    break;
                case Coffee::Key::D:
                    moveRight = true;
                    break;
                default:
                    return false;
                }
            }
        }
        return true;
    }

    bool Vehicle::OnKeyRelease(KeyReleasedEvent& event)
    {
        std::string key = event.ToString();
        printf("\n%s", key.c_str());

        if (selectedEntity)
        {
            const float moveSpeed = 1.0f; // �ƶ��ٶ�
            auto& position = selectedEntity.GetComponent<TransformComponent>().Position;

            if (selectedEntity.GetComponent<TagComponent>().Tag == "FINAL_MODEL_74.fbx")
            {

                if (key == "KeyReleasedEvent: 26")
                {
                    moveFront = false;
                }
                if (key == "KeyReleasedEvent: 22")
                {
                    moveBack = false;
                }
                if (key == "KeyReleasedEvent: 7")
                {
                    moveRight = false;
                }
                if (key == "KeyReleasedEvent: 4")
                {
                    moveLeft = false;
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