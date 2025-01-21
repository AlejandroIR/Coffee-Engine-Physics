#pragma once

#include <functional>
#include <vector>

namespace Coffee
{

    class Collider
    {
      public:
        Collider();
        virtual ~Collider();

        // Callback de colisi�n: se llama cuando este colisionador interact�a con otro
        using CollisionCallback = std::function<void(Collider* other)>;

        void AddCollisionListener(const CollisionCallback& callback);
        void OnCollision(Collider* other);

      private:
        std::vector<CollisionCallback> m_collisionListeners;
    };

} // namespace Coffee
