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

        
        Entity selectedEntity;

      public:

        // ���·���
        void handleInput(const Uint8* keyState); // �����������
        void update();           // ���³���״̬


        void OnEvent(Coffee::Event& event);

        bool OnKeyPressed(KeyPressedEvent& event);

        SceneTreePanel m_SceneTreePanel;
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
