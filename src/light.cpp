//possibly move the color class to tylers data structurs file
class Color{
	public:
		int r, g, b;
}
class LightSource{
	protected:
		Color c;
		
	public:
		
		int getR(){
			return c.r;
		}
		
		int getG(){
			return c.g;
		}
		
		int getB(){
			return c.b;
		}
		
		Color getColor(){
			return c;
		}
		   
}
class pointLight: public lightSource{
	protected:
		Point p;
		float intensity;
	public:
		float getIntensity(){
			return intensity;
		}	
		Point getPoint(){
			return p;
		}	
}
class directionalLight: public lightSource{
	protected:
		Vector v;
		
	public:
		float getI(){
			return v.i;
		}
		float getJ(){
			return v.j;
		}
		float getK(){
			return v.k;
		}
		DVector getVector{
			return v;
		}
		
		
}
class spotLight: public directionalLight{
	protected:
		float theta;
		Point p;		
	public:
		float getTheta(){
			return theta;
		}
		Point getPoint(){
			Point p;
		}
}

