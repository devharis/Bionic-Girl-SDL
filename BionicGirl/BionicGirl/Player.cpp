#include "Player.h"

const float SPEED = .2f;

Player::Player(Vector2D position, const int width, const int height, const string textureId)
{
	m_position = position; 
	m_width = width;  
	m_height = height; 
	m_textureId = textureId;
}

void Player::update(const float deltaTime) {
	//m_velocity.setX(1);
    //m_acceleration.setX(SPEED);
    
    m_velocity.setX(0);
    m_velocity.setY(0);
    
    m_acceleration.setX(0);
    m_acceleration.setY(0);
    
    handleInput();
    
    GameObject::update(deltaTime);

	//auto x_position = m_position.getX();
    //auto y_position = m_position.getY();
	//auto new_x_position = x_position + (deltaTime * SPEED);
    //auto new_y_position = y_position + (deltaTime * SPEED);
	//m_position.setX(new_x_position);
    //m_position.setY(new_y_position);'
    
	//cout << new_x_position;
	//cout << "\n";
}

void Player::draw() {
	GameObject::draw();
}

void Player::handleInput(){
    if (InputHandlerInst::Instance()->joysticksInitialised())
        {
            //for analog sticks of the first joystick
            if ((InputHandlerInst::Instance()->xvalue(0, 1) > 0) || (InputHandlerInst::Instance()->xvalue(0, 1) < 0))
            {
                //if we are moving the player with analog stick while pressing Y
                //it will get an acceleration of 2 in that direction
                m_velocity.setX((float)1 * InputHandlerInst::Instance()->xvalue(0, 1));
                if (InputHandlerInst::Instance()->getButtonState(0, 3))    //Button 3(Yellow)
                {
                    //give the player some acceleration
                    m_acceleration.setX((float)2 * InputHandlerInst::Instance()->xvalue(0, 1));
                }
            }

            if ((InputHandlerInst::Instance()->yvalue(0, 1) > 0) || (InputHandlerInst::Instance()->yvalue(0, 1) < 0))
            {
                m_velocity.setY((float)1 * InputHandlerInst::Instance()->yvalue(0, 1));
                if (InputHandlerInst::Instance()->getButtonState(0, 3))
                {
                    m_acceleration.setY((float)2 * InputHandlerInst::Instance()->yvalue(0,1));
                }
            }

            if ((InputHandlerInst::Instance()->xvalue(0, 2) > 0) || (InputHandlerInst::Instance()->xvalue(0, 2) < 0))
            {
                m_velocity.setX((float)1 * InputHandlerInst::Instance()->xvalue(0, 2));
                if (InputHandlerInst::Instance()->getButtonState(0, 3))
                {
                    m_acceleration.setX((float)2 * InputHandlerInst::Instance()->xvalue(0, 1));
                }
            }

            if ((InputHandlerInst::Instance()->yvalue(0, 2) > 0) || (InputHandlerInst::Instance()->yvalue(0, 2) < 0))
            {
                m_velocity.setY((float)1 * InputHandlerInst::Instance()->yvalue(0, 2));
                if (InputHandlerInst::Instance()->getButtonState(0, 3))
                {
                    m_acceleration.setY((float)2 * InputHandlerInst::Instance()->yvalue(0, 1));
                }
            }
            /*    Code as in the book
            //for buttons of the first joystick
            if (TheInputHandler::Instance()->getButtonState(0, 3))    //Button 3(Yellow)
            {
                //give the player some acceleration
                m_acceleration.setX(1);
            }
            */
        }

        //check for mouse button input
        if (InputHandlerInst::Instance()->getMouseButtonState(LEFT))
        {
            m_acceleration.setX(-3);
        }
        if (InputHandlerInst::Instance()->getMouseButtonState(RIGHT))
        {
            m_acceleration.setX(3);
        }

        //check for mouse motion input
        //commenting this feature as I don't want player to follow mouse
        //uncomment the following code to enable the feature
        //

        //Vector2D* target;
        //target = new Vector2D(0, 0);    //now initialized in constructor

        //target = InputHandlerInst::Instance()->getMousePosition();

        //m_velocity = (*target - m_position);

        //m_velocity /= 50;    //slow down the follow movement
        
        //

        //Adding keyboard controls
        //UP DOWN RIGHT LEFT for movement
        //Right Ctrl for Acceleration
        if (InputHandlerInst::Instance()->isKeyDown(SDL_SCANCODE_RIGHT))
        {
            m_velocity.setX(2);
            //check if Right Ctrl is pressed, provide acc. if true
            if (InputHandlerInst::Instance()->isKeyDown(SDL_SCANCODE_RCTRL))
            {
                m_acceleration.setX(2.5);
            }
        }
        if (InputHandlerInst::Instance()->isKeyDown(SDL_SCANCODE_LEFT))
        {
            m_velocity.setX(-2);
            //check if Right Ctrl is pressed, provide acc. if true
            if (InputHandlerInst::Instance()->isKeyDown(SDL_SCANCODE_RCTRL))
            {
                m_acceleration.setX(-2.5);
            }
        }
        //remember the cartesian plane is inverted along Y Axis
        if (InputHandlerInst::Instance()->isKeyDown(SDL_SCANCODE_UP))
        {
            m_velocity.setY(-2);
            //check if Right Ctrl is pressed, provide acc. if true
            if (InputHandlerInst::Instance()->isKeyDown(SDL_SCANCODE_RCTRL))
            {
                m_acceleration.setY(-2.5);
            }
        }
        if (InputHandlerInst::Instance()->isKeyDown(SDL_SCANCODE_DOWN))
        {
            m_velocity.setY(2);
            //check if Right Ctrl is pressed, provide acc. if true
            if (InputHandlerInst::Instance()->isKeyDown(SDL_SCANCODE_RCTRL))
            {
                m_acceleration.setY(2.5);
            }
        }
}

void Player::clean() {
	delete this;
}
