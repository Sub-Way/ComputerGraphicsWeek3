# ComputerGraphicsWeek3

## 3주차. 2D 그래픽스 프로그래밍

### 1.	OpenGL을 이용해서 자신이 좋아하는 2D 캐릭터를 그리시오. (70점)
-	Primitive의 종류를4개 이상 사용했는가? 각각의 종류마다 10점
-	색깔이 들어갔는가? 20점
-	캐릭터의 완성도10점

![image](https://user-images.githubusercontent.com/22046757/61993133-1da42d00-b0a2-11e9-83d7-358f6646d761.png)

 




### 2.	상 / 하 / 좌 / 우 버튼을 누르면 캐릭터가 움직이도록 구현하시오.  (20점)
-	상 / 하 / 좌 / 우 버튼을 눌렀을 때 동작을 하는가? 각각의 동작마다 5점
-	레포트의 완성도 10점

### 결과화면
 


 
#### 주요 소스 코드

#### 1. GL_TRIANGLE_FAN
~~~
const int triangle_num = 2000;
		float dtheta = 3.141592 / triangle_num;
		float r = 0.5;
float theta = 0;
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
~~~
윗 몸통과 아랫 몸통은 각각 반원으로 이루어져 있다. 따라서 반원이 되도록 dtheta 값을 수정하였다. 그리고 위의 반원과 다르게 아래 반원은 -x,-y로 값을 바꿔 GL_TRIANGLE_FAN함수를 적용시켰다. 그리고 위의 반원 아랫부분에 약간의 굴곡을 주기위해 반원 형태의 타원을 만들어 붙였고, y값에 0.15를 곱해주어 타원이 되도록 만들었다.  

![image](https://user-images.githubusercontent.com/22046757/61995923-64594d80-b0c9-11e9-8733-f5ff412f44d9.png)


#### 2.GL_LINES
~~~
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
~~~
캐릭터의 눈을 만들기 위해 GL_LINES를 이용하였다. 두 점의 좌표 값을 입력해 GL_LINES로 두 점을 이었다. 그리고 glLineWidth를 이용하여 선의 두께를 조절하였다.
 
![image](https://user-images.githubusercontent.com/22046757/61995932-7e932b80-b0c9-11e9-90d7-0ac21e0e60bc.png)
 
#### 3. GL_QUADS
~~~
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
~~~
캐릭터 눈의 흰자부분을 만들기 위해 GL_QUADS를 사용했다. 4개의 좌표 값을 입력하고 GL_QUADS를 이용하여 연결하고 glColor3f를 이용해 사각형 부분이 흰색이 되도록 만들었다.
 
![image](https://user-images.githubusercontent.com/22046757/61995942-8fdc3800-b0c9-11e9-917a-edb39b2992b3.png)

~~~
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
~~~

추가적으로 GL_TRIANGLE_FAN 함수를 이용하여 타원형의 눈동자를 생성해준다.
 
![image](https://user-images.githubusercontent.com/22046757/61995950-a5e9f880-b0c9-11e9-92fd-f4efd2f1bb58.png)
 
#### 4. GL_POINTS
~~~
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
~~~
GL_POINTS를 이용하여 몸통 곡선의 테두리와 캐릭터 바깥부분의 테두리를 생성한다. 포인트의 크기를 정하고 for문을 이용해 원의 둘레를 돌면서 점을 찍는 형태로 만든다.
 
![image](https://user-images.githubusercontent.com/22046757/61995955-b8fcc880-b0c9-11e9-81fd-19e4f4720249.png)
 
#### 5. GL_LINE_STRIP
~~~
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
~~~

GL_LINE_STRIP함수를 이용하여 입력한 좌표 값들의 점들을 순서대로 이어준다. 이를 통해서 캐릭터의 추가적인 꾸밈 효과를 주었다.
 
![image](https://user-images.githubusercontent.com/22046757/61995959-c6b24e00-b0c9-11e9-82d2-e8c4596a761a.png)
 
#### 상/하/좌/우
~~~
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
~~~
Key_callback함수를 만들어서 키보드의 상/하/좌/우 키를 입력받으면  x,y좌표의 값이 증가 감소 시켜 캐릭터가 움직이도록 하였다. X_center와 wx_center의 값이 반대인 이유는 glVertex2f의 값을 반대로 입력했기 때문에 반대로 해야 같은 방향으로 움직이기 때문이다.
 
![image](https://user-images.githubusercontent.com/22046757/61995965-d9c51e00-b0c9-11e9-9e70-43cdda2af762.png)
