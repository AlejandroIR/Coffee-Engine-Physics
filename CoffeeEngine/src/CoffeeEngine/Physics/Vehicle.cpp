#include "Vehicle.h"
#include <CoffeeEngine/Scene/Components.h>



namespace Coffee
{

    Vehicle::Vehicle(double mass, double initialX, double initialY)
        : mass(mass), positionX(initialX), positionY(initialY), velocityX(0.0), velocityY(0.0), accelerationX(0.0),
          accelerationY(0.0), forceX(0.0), forceY(0.0)
    {
    }

    // �����������
    void Vehicle::handleInput(const Uint8* keyState)
    {
        forceX = 0.0; // ������
        forceY = 0.0;

        // ���ݰ���ʩ����
        if (keyState[SDL_SCANCODE_W])
        {                          // ���� W ��
            forceY -= forceAmount; // ����ʩ����
            printf("W");

            selectedEntity.GetComponent<TransformComponent>().Position.x += 1;
        }
        if (keyState[SDL_SCANCODE_S])
        {                          // ���� S ��
            forceY += forceAmount; // ����ʩ����
            printf("S");
        }
        if (keyState[SDL_SCANCODE_A])
        {                          // ���� A ��
            forceX -= forceAmount; // ����ʩ����
            printf("A");
        }
        if (keyState[SDL_SCANCODE_D])
        {                          // ���� D ��
            forceX += forceAmount; // ����ʩ����
            printf("D");
        }

        // ������ٶ�
        if (mass > 0)
        {
            accelerationX = forceX / mass;
            accelerationY = forceY / mass;
        }
        else
        {
            accelerationX = 0.0;
            accelerationY = 0.0;
        }
    }

    // ���³���״̬
    void Vehicle::update()
    {
        // velocityX += accelerationX * deltaTime; // �����ٶ�
        // velocityY += accelerationY * deltaTime;

        // positionX += velocityX * deltaTime; // ����λ��
        // positionY += velocityY * deltaTime;

         //printf("a");

        if (selectedEntity)
        {
            printf("yeess");
        }


        /* SDL_Event event;
        while (SDL_PollEvent(&event))
        {

            if (event.key.scancode, 0){
            
            }

            m_ImGuiLayer->ProcessEvents(event);
            switch (event.type)
            {
                if (event.key.repeat)
                {
                    KeyPressedEvent e(event.key.scancode, 1);

                }
                else
                {
                    KeyPressedEvent e(event.key.scancode, 0);

                }
            }
        }*/

    }

    void Vehicle::OnEvent(Coffee::Event& event)
    {

        EventDispatcher dispatcher(event);
        dispatcher.Dispatch<KeyPressedEvent>(COFFEE_BIND_EVENT_FN(Vehicle::OnKeyPressed));

    }

    bool Vehicle::OnKeyPressed(KeyPressedEvent& event)
    {
        //if (event.IsRepeat() > 0)
        //    return false;

        switch (event.GetKeyCode())
        {
        case Coffee::Key::Q:

               printf("sss");
            break;
        }
        return false;
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
        update();
        printf("s");
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