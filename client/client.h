#ifndef CLIENT_H
#define CLIENT_H

class client{
public:
	client();
	~client();
	void initialize();
	void start();
	void render();
	void update();
	void run();
	void stop();
private:
	bool m_initialized;
	float m_time;
	float m_deltaTime;
	float m_frameTime;
	float m_frameRate;
	int m_frameCount;
	float m_fps;
	float m_lastFrameTime;
	float m_currentFrameTime;
	enum class State {
		STOPPED,
		RUNNING,
		INITIALIZING,
		RENDERING
	};
	State m_State;

};



#endif // !CLIENT_H


