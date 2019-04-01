class Entidade{
	public:
		int x,y,z;
		double angulo;
		Entidade (){
			this->angulo=0;
		}
		Entidade (int x=0,int y=0,int z=0){
			this->x=x;
			this->y=y;
			this->z=z;
		}
		void update(){
			this->angulo+=0.3;
		}

		void display(){
			glPushMatrix();
			glutWireCube(5);
			glPopMatrix();
		}
};
