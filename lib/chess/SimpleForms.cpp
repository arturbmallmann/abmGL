#include "SimpleForms.h"
void piramid(){
 glPushMatrix();
 for(int i=0;i<4;i++){
  glRotatef(90,0,1,0);
  glPushMatrix();
   glColor3d((i%2)*255,(i%3)*255,(i%4)*255);
//   glRotatef(45,1,0,0);
//   glTranslatef(0,); 
   glBegin(GL_TRIANGLES);
    glVertex3f(0,0,0);
    glVertex3f(-1,-1,-1);
    glVertex3f(1,-1,-1);

   glEnd();
  glPopMatrix();
 }
 glPopMatrix();
}

void chessTable(double scale,double chess_size){
 double color=0;
 glPushMatrix();
 glRotatef(90,1.0f,0,0);
 glScalef(scale,scale,scale);
 glTranslatef(-(chess_size/2)-1, -(chess_size/2)-1,0);
 for(int x=0; x<chess_size; x++){
  glTranslatef(0,1,0);
  glPushMatrix();
  for(int z=0; z<chess_size; z++){
    color=(x+z)%2;
    glColor3f(0,0,color);
    glTranslatef(1,0,0);

    glRectf(0,0,1,1);
  }
  glPopMatrix();
 }
 glLoadIdentity();
 glPopMatrix();
}
