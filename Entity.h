class Entity
{
private:
    int* m_animation_right = NULL, // move to the right
        * m_animation_left = NULL, // move to the left
        * m_animation_up   = NULL, // move upwards
        * m_animation_down = NULL; // move downwards

    glm::vec3 m_position;
    glm::vec3 m_velocity;
    glm::vec3 m_acceleration;

    // ————— TRANSFORMATIONS ————— //
    float     m_speed;
    float     m_angle = 0.0f;
    glm::vec3 m_movement;
    glm::mat4 m_model_matrix,
              m_win_matrix,
              m_lose_matrix;

    int m_width  = 1,
        m_height = 1;
public:
    bool Win;
    bool GameOver = false;
    // ————— STATIC VARIABLES ————— //
    static const int SECONDS_PER_FRAME = 4;
    static const int LEFT = 0,
        RIGHT = 1,
        UP    = 2,
        DOWN  = 3;

    // ————— ANIMATION ————— //
    int** m_walking = new int* [4]
        {
            m_animation_left,
            m_animation_right,
            m_animation_up,
            m_animation_down
        };

    int m_animation_frames = 0,
        m_animation_index = 0,
        m_animation_cols = 0,
        m_animation_rows = 0;

    int* m_animation_indices = NULL;
    float m_animation_time = 0.0f;

    GLuint    m_texture_id;

    // ————— METHODS ————— //
    Entity();
    ~Entity();
    void draw_sprite_from_texture_atlas(ShaderProgram* program, GLuint texture_id, int index);
    bool const check_collision(Entity* other) const;

    void update(float delta_time, Entity* collidable_entities, int collidable_entity_count);
    void render(ShaderProgram* program);
    

    void move_left()    { m_movement.x = -1.0f; };
    void move_right()   { m_movement.x = 1.0f;  };
    void move_up()      { m_movement.y = 1.0f;  };
    void move_down()    { m_movement.y = -1.0f; };
    void rotate_left()  { m_angle += 0.05f; };
    void rotate_right() { m_angle -= 0.05; };
    void accelerate_up() { 
        m_acceleration.x += glm::cos(glm::radians(m_angle))  * 0.001f;
        m_acceleration.y += glm::sin(glm::radians(m_angle)) * 0.001f;
    }

    // ————— GETTERS ————— //
    glm::vec3 const get_position()     const { return m_position; };
    glm::vec3 const get_velocity()     const { return m_velocity; };
    glm::vec3 const get_acceleration() const { return m_acceleration; };
    glm::vec3 const get_movement()     const { return m_movement; };
    float     const get_speed()        const { return m_speed; };
    bool      const get_Win()          const { return Win; };
    bool      const get_GameOver()     const { return GameOver; };

    // ————— SETTERS ————— //
    void const set_position(glm::vec3 new_position) { m_position = new_position; };
    void const set_velocity(glm::vec3 new_velocity) { m_velocity = new_velocity; };
    void const set_acceleration(glm::vec3 new_position) { m_acceleration = new_position; };
    void const set_movement(glm::vec3 new_movement) { m_movement = new_movement; };
    void const set_speed(float new_speed) { m_speed = new_speed; };
};
