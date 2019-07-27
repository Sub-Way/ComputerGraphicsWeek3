#include <GLFW/glfw3.h>
#include<iostream>
using namespace std;

float x_center = 0.0f;
float y_center = 0.0f;
float wx_center = 0.0f;
float wy_center = 0.0f;

void key_callback(GLFWwindow*window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_LEFT && action == GLFW_PRESS) {
		x_center -= 0.05;
		wx_center += 0.05;
	}
	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS) {
		x_center += 0.05;
		wx_center -= 0.05;
	}

	if (key == GLFW_KEY_UP && action == GLFW_PRESS) {
		y_center += 0.05;
		wy_center -= 0.05;
	}
	if (key == GLFW_KEY_DOWN && action == GLFW_PRESS) {
		y_center -= 0.05;
		wy_center += 0.05;
	}
}


int main() {
	GLFWwindow * window;

	int width = 1024;
	int height = 800;

	glfwInit();

	if (!glfwInit()) {
		return -1;
	}

	window = glfwCreateWindow(width, height, "week 3. 2D Graphics programming", NULL, NULL);
	glfwSetKeyCallback(window, key_callback);
	glfwMakeContextCurrent(window);
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);
	const float aspect_ratio = (float)width / (float)height;  
	glOrtho(-1.5*aspect_ratio, 1.5 * aspect_ratio, -1.5, 1.5, -1, 1);
	glClearColor(0, 0, 0, 0); //RGB 값은 0~1사이 이므로 255로 나눠준다. alpha는 투명화 정도

	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	while (!glfwWindowShouldClose(window)) {
		const int triangle_num = 2000;
		float dtheta = 3.141592 / triangle_num;
		float r = 0.5;
		float theta = 0;

		glClear(GL_COLOR_BUFFER_BIT);

		GLfloat sizes[2];
		GLfloat step;
		GLfloat fcursize;
		glGetFloatv(GL_LINE_WIDTH_RANGE, sizes);

		fcursize = sizes[0];
		fcursize += 2.0f;
	
		//윗몸통
		glColor3f(1, 0, 0); 
		glVertex2d(x_center, y_center);
		for (int i = 0; i <= triangle_num; i++, theta += dtheta) {

			float x = r * cos(theta) + x_center;
			float y = r * sin(theta) + y_center;
			
			glBegin(GL_TRIANGLE_FAN);
			glVertex2f(x, y);

		}
		glEnd();

		//아랫몸통
		glColor3f(1, 1, 1);
		glVertex2d(wx_center, wy_center);
		for (int i = 0; i <= triangle_num; i++, theta -= dtheta) {

			float x = r * cos(theta) + wx_center;
			float y = r * sin(theta) + wy_center;

			glBegin(GL_TRIANGLE_FAN);
			glVertex2f(-x, -y);
		}
		glEnd();

		//아랫타원몸통
		glColor3f(1, 0, 0);
		glVertex2d(wx_center, wy_center);
		for (int i = 0; i <= triangle_num; i++, theta += dtheta) {

			float x = r * cos(theta) + wx_center;
			float y = 0.15*r * sin(theta) + wy_center;

			glBegin(GL_TRIANGLE_FAN);
			glVertex2f(-x, -y);
		}
		glEnd();


		//위눈썹
		glColor3f(0, 0, 0);
		glLineWidth(fcursize);
		glBegin(GL_LINES);
		glVertex2f(x_center -0.1, y_center+0.1);
		glVertex2f(x_center -0.3, y_center+0.25);
		glEnd();

		glColor3f(0, 0, 0);
		glLineWidth(fcursize);
		glBegin(GL_LINES);
		glVertex2f(x_center+0.1, y_center+0.1);
		glVertex2f(x_center+0.3, y_center+0.25);
		glEnd();

		//눈아래
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2f(x_center -0.1, y_center+0.05);
		glVertex2f(x_center -0.3, y_center+0.05);
		glEnd();

		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2f(x_center+0.1, y_center+0.05);
		glVertex2f(x_center+0.3, y_center+0.05);
		glEnd();

		//미간부분
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2f(x_center -0.1, y_center+0.1);
		glVertex2f(x_center -0.1, y_center+0.2);
		glEnd();

		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2f(x_center+0.1, y_center+0.1);
		glVertex2f(x_center+0.1, y_center+0.2);
		glEnd();

		//오른쪽흰자
		glColor3f(1, 1, 1);
		glBegin(GL_QUADS);
		glVertex2f(x_center+0.28, y_center+0.05);
		glVertex2f(x_center+0.1, y_center+0.05);
		glVertex2f(x_center+0.1, y_center+0.1);
		glVertex2f(x_center+0.3, y_center+0.25);
		glEnd();

		//왼쪽흰자
		glColor3f(1, 1, 1);
		glBegin(GL_QUADS);
		glVertex2f(x_center -0.28, y_center+0.05);
		glVertex2f(x_center -0.1, y_center+0.05);
		glVertex2f(x_center -0.1, y_center+0.1);
		glVertex2f(x_center -0.3, y_center+0.25);
		glEnd();

		//오른쪽 눈동자
		glColor3f(0, 0, 0);
		glVertex2d(x_center, y_center);
		for (int i = 0; i <= triangle_num; i++, theta += dtheta*2) {

			float x = 0.015 * cos(theta) + x_center + 0.15;
			float y = 0.015 * 1.5 * sin(theta) + y_center + 0.12;

			glBegin(GL_TRIANGLE_FAN);
			glVertex2f(x, y);
		}
		glEnd();

		//왼쪽 눈동자
		glColor3f(0, 0, 0);
		glVertex2d(x_center, y_center);
		for (int i = 0; i <= triangle_num; i++, theta += dtheta * 2) {

			float x = 0.015 * cos(theta) - x_center + 0.15;
			float y = 0.015 * 1.5 * sin(theta) + y_center + 0.12;

			glBegin(GL_TRIANGLE_FAN);
			glVertex2f(-x, y);
		}
		glEnd();

		//가운데 선
		glPointSize(2.0);
		glBegin(GL_POINTS);
		for (float i = 1.5707; i < 4.7122; i = i + 0.01)
		{
			glColor3f(0.0, 0.0, 0.0);
			glVertex3f(x_center+0.5*sin(i) - 0.0, y_center+0.15*0.5*cos(i) + 0.0, 0.0);
		}
		glEnd();

		//테두리
		glPointSize(2.0);
		glBegin(GL_POINTS);
		for (float i = 0; i < 6.2829; i = i + 0.01)
		{
			glColor3f(1, 1, 51/255); //반사광
			glVertex3f(x_center+0.5*sin(i) - 0.0, y_center+0.5*cos(i) + 0.0, 0.0);
		}
		glEnd();

		glColor3f(1, 1, 51/255);
		glBegin(GL_LINE_STRIP);
		glVertex2f(x_center -0.5, y_center+0.0);
		glVertex2f(x_center -0.63, y_center+0.2);
		glVertex2f(x_center -0.87, y_center+0.12);
		glVertex2f(x_center -1.24, y_center+0.25);
		glEnd();

		glColor3f(1, 1, 51 / 255);
		glBegin(GL_LINE_STRIP);
		glVertex2f(x_center+0.31, y_center -0.24);
		glVertex2f(x_center+0.57, y_center+0.02);
		glVertex2f(x_center+0.78, y_center -0.16);
		glVertex2f(x_center+0.97, y_center+0.25);
		glEnd();

		glColor3f(1, 1, 51 / 255);
		glBegin(GL_LINE_STRIP);
		glVertex2f(x_center-0.31, y_center - 0.25);
		glVertex2f(x_center-0.61, y_center-0.29);
		glVertex2f(x_center-0.42, y_center -0.49);
		glVertex2f(x_center-0.78, y_center-0.39);
		glEnd();

		glColor3f(1, 1, 51 / 255);
		glBegin(GL_LINE_STRIP);
		glVertex2f(x_center + 0.31, y_center + 0.25);
		glVertex2f(x_center + 0.61, y_center + 0.29);
		glVertex2f(x_center + 0.42, y_center + 0.49);
		glVertex2f(x_center + 0.78, y_center + 0.39);
		glEnd();

		glColor3f(1, 1, 51 / 255);
		glBegin(GL_LINE_STRIP);
		glVertex2f(x_center - 0.31, y_center + 0.35);
		glVertex2f(x_center - 0.61, y_center + 0.42);
		glVertex2f(x_center - 0.42, y_center + 0.59);
		glVertex2f(x_center - 0.78, y_center + 0.78);
		glEnd();

		glColor3f(1, 1, 51 / 255);
		glBegin(GL_LINE_STRIP);
		glVertex2f(x_center + 0.11, y_center - 0.25);
		glVertex2f(x_center + 0.31, y_center - 0.42);
		glVertex2f(x_center + 0.19, y_center - 0.61);
		glVertex2f(x_center + 0.42, y_center - 0.78);
		glEnd();

		glfwSwapBuffers(window); //더블 버퍼링을 위해 이용

		glfwPollEvents();//콜백 함수의 발생여부를 파악한다.
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}