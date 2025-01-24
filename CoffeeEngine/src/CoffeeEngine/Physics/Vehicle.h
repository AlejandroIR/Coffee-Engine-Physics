#ifndef VEHICLE_H
#define VEHICLE_H
#include <SDL3/SDL.h> // ���� SDL3 ͷ�ļ���֧�ּ�������
#include "../../../../CoffeeEditor/Panels/SceneTreePanel.h"
#include <CoffeeEngine/Events/KeyEvent.h>



namespace Coffee
{

    class Vehicle
    {
      public:
        // Ĭ�Ϲ��캯��
        Vehicle()
            : mass(0.0), positionX(0.0), positionY(0.0), velocityX(0.0), velocityY(0.0), accelerationX(0.0),
              accelerationY(0.0), forceX(0.0), forceY(0.0)
        {
            // ��ʼ����Ա����ΪĬ��ֵ
        }

        // ԭ�еĹ��캯��
        Vehicle(double mass, double initialX = 0.0, double initialY = 0.0);

      private:
        double mass;          // �������� (kg)
        double positionX;     // X ��λ�� (m)
        double positionY;     // Y ��λ�� (m)
        double velocityX;     // X ���ٶ� (m/s)
        double velocityY;     // Y ���ٶ� (m/s)
        double accelerationX; // X ����ٶ� (m/s^2)
        double accelerationY; // Y ����ٶ� (m/s^2)

        double forceX; // X ���ϵĵ�ǰ���� (N)
        double forceY; // Y ���ϵĵ�ǰ���� (N)

        const double forceAmount = 500.0; // ÿ�ΰ���ʩ�ӵ�����С (N)

        bool moveFront = false;
        bool moveBack = false;
        bool moveLeft = false;
        bool moveRight = false;

        // ������ر���
        float speed = 0.0f;         // ��ǰ�ٶ�
        float maxSpeed = 50.0f;     // ����ٶ�
        float acceleration = 10.0f; // ���ٶ�
        float deceleration = 5.0f;  // ���ٶ�
        float maxTurnSpeed = 45.0f; // ���ת���ٶȣ��Ƕ�/�룩������ʱ��Ч
        float drag = 2.0f;          // ����
        float rotation = 0.0f;      // ��ǰ����ǣ������ԽǶȱ�ʾ��

        // ת�����
        float turnInput = 0.0f;        // ��ǰת������ (-1 ��ת, 1 ��ת)
        float currentTurnSpeed = 0.0f; // ��ǰʵ��ת���ٶ�

        Entity selectedEntity;
        SceneTreePanel m_SceneTreePanel;

      public:

        // ���·���
        void handleInput(const Uint8* keyState); // �����������
        void update(float dt);           // ���³���״̬


        void OnEvent(Coffee::Event& event);

        bool OnKeyPressed(KeyPressedEvent& event);

        bool OnKeyRelease(KeyReleasedEvent& event);

        // ��ȡ����
        double getPositionX() const;
        double getPositionY() const;
        double getVelocityX() const;
        double getVelocityY() const;

        void setEntity(Entity entity);       
        Entity getEntity();       

        //ImGuiLayer* m_ImGuiLayer;
    };

    
} // namespace Coffee
#endif // VEHICLE_H
