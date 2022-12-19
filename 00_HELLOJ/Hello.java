class Model {
	double weights[];
	
	Model() {
		System.out.println("Constructing a Model instance...");
	}
}

class Hello {
	public static void main(String args[]){
		System.out.println("Instantiating a Model instance...");
		System.out.println("Hello, world");
		Model model = new Model();
		  
	}
}

