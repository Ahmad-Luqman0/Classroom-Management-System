#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<ctime>
#include<stdlib.h>
using namespace std;

const int MAX=100;
void menue1();
void menuelogin();
void teachermenu();
void menueloginteacher();
void quizmenu(string x);
char* generatepswrd();
void studentmenu();
void Registration();
void GenerateKey();
void RemoveMarker();
void analytics(string name, int obt, int total, string course);



class Login{
private:
	string username;
	string password;
public:
	Login(){
		username=" ";
		password=" ";
	 
	}

	Login(string username){
		this->username=username;
		password=" ";
	}

	Login(string username, string password){
		this->username=username;
		this->password=password;
	}

	string getusername(){
		return username;
	}

	string getpassword(){
		return password;
	}

	void setusername(string username){
		this->username=username;
	}

	void setpassword(string password){
		this->password=password;
	}

	bool checkname(){			//check if the file contains the students name

	string name=getusername();
	ifstream infile("Data.csv");
	string row;
	
	int colnum=3;
	bool flag;
	
	while(getline(infile, row)){
		stringstream ss(row);
		string value;
		
		for(int i=1; i<=colnum; i++){
		getline(ss, value, ',');
		}
		
		if(value==name){		//if name is true it returns true
			flag=true;
			break;
		}
        
	}
	
		if(flag!=true){				//if name not found prints Name Not found and returns false
			cout<<"Name not found";
			cout<<endl;
			}

		return flag;
	}

	bool validate(){			//check if username and password are both of same user
		string user=getusername();
		string pass=getpassword();
		
		ifstream infile;
		infile.open("Users.csv");		//open file of usernames and passwords


		string row;
		while(getline(infile, row)){
		
			size_t pos=row.find(",");			
			string user1=row.substr(0, pos);
			string pass1=row.substr(pos + 1);

			if(user==user1 && pass==pass1){		//if current row of csv file matches the username and password provided it returns true and login successfull
				infile.close();
				return true;
			}
			
		}


		return false;

	}



};

class Courses{
protected:
    int courses[11];
	string c[11];
	int arr[11];
	int totalcourses;
	string question[MAX];
	string answers[MAX];
	string correctans[MAX];
	int obtainedMarks;
	int totalMarks;
	
public:
    Courses(){
        for(int i=0; i<11; i++){
            courses[i]=0;
        }

		for(int i=0; i<11; i++){
            c[i]=" ";
        }
        
        for(int i=0; i<11; i++){
            arr[i]=0;
        }
		totalcourses=this->findsumcourses();

		for(int i=0; i<MAX; i++){
				question[i]="";
		}
			
		for(int i=0; i<MAX; i++){
				answers[i]="";
		}
		
		for(int i=0; i<MAX; i++){
				correctans[i]="";
		}
		
		obtainedMarks=0;
		totalMarks=0;
    }

    void findname(string x){
	ifstream infile("Data.csv");
    string row;
    int rownum=0;
    int colnum=3;
    int i;

    while (getline(infile, row)) {
        rownum++;
        stringstream ss(row);
        string value;

        for (i=1; i<=colnum; i++) {
            getline(ss, value, ',');
        }
		
		int alpha=0;
		
        if (value==x){
			int x=0;
            while (getline(ss, value, ',')) {
				if(value=="1")
				{
					this->courses[x]=1;
					arr[alpha]=x;
					alpha++;
					
				}
				else{
					this->courses[x]=0;
				}
							
				x++;
            }
            return;
        }
    }

    cout<<"Error!!!!";
    }
    
    int findsumcourses(){
    	int sum;
    	
    	for(int i=0; i<11; i++){
    		sum=sum+courses[i];
		}
		return sum;
	}

    void displaycourses(){
        
        cout<<"Courses OFFERED"<<endl;
        int x=0;
        for(int i=0; i<11; i++){
            if(i==0){
                if(this->courses[i]==1){
					this->c[x]="Programming Fundamentals";
                    x++;
                }
            }
            else if(i==1){
                if(this->courses[i]==1){
					this->c[x]="Object Oriented Programming";
                    x++;

                }
            }
            else if(i==2){
                if(this->courses[i]==1){
					this->c[x]="Introduction To Computing";
                    x++;
                }
            }
            else if(i==3){
                if(this->courses[i]==1){
					this->c[x]="Data Structures";
                    x++;
                }
            }
            else if(i==4){
                if(this->courses[i]==1){
					this->c[x]="Analysis of Algorithms";
                    x++;
                }
            }
            else if(i==5){
                if(this->courses[i]==1){
					this->c[x]="Software Requirements Engineering";
                    x++;
                }
            }
            else if(i==6){
                if(this->courses[i]==1){
					this->c[x]="Research Methodology";
                    x++;
                }
            }
            else if(i==7){
                if(this->courses[i]==1){
					this->c[x]="Big Data Analytics";
                    x++;
                }
            }
            if(i==8){
                if(this->courses[i]==1){
					this->c[x]="Artificial Intelligence";
                    x++;
                }
            }
            else if(i==9){
                if(this->courses[i]==1){
					this->c[x]="Deep Learning";
                    x++;
                }
            }
            else if(i==10){
                if(this->courses[i]==1){
					this->c[x]="Digital Image Processing";
                    x++;
                }
            }
        }     

		for(int i=0; i<11; i++){
			if(c[i]!=" "){
				cout<<c[i]<<"\t";
			}
			
		}
		cout<<endl;

		
		}

    void Selectcourse(){
		int totalcourses=this->findsumcourses();
		cout<<endl;
    	cout<<"You are enrolled in  : "<<totalcourses<<" Courses "<<endl;
		
		
	}

	string checkQuiz(){
		int x;
		x=findsumcourses();
		
		string fileName="quiz.txt";
		string fline;
		string line;

		ifstream file(fileName);
		if(file.is_open()){
			if(getline(file, line)){        
				fline=line;
				}
			else{
				cout<<"No Quiz Present "<<endl;
				}
			file.close();
			}
		
		bool flag=false;

		for(int i=0; i<11; i++)
		{
			if(c[i]==fline){
				flag=true;
			}
		}
		int y;
		if(flag==true){
			cout<<endl;
			cout<<"Quiz is present for "<<fline<<endl;

			cout<<endl;
			cout<<"Press 1 to Attempt Quiz"<<endl;
			cout<<"Pess 2 to Logout"<<endl;
			cout<<"Press 3 to go to Main Menue"<<endl;
			cout<<"Press 0 to exit "<<endl;
			int a;
			while(1){
				cout<<"Your choice is: ";
				cin>>a;
				if(a==1){
					// a=takeAnswers();
					// correctanswers();
					// calculateResult(a);
					// calculateTotal(a);
					return fline;
					break;
				}
				else if(a==2){
					menuelogin();
					break;
					
				}
				else if(a==3){
					menue1();
					break;
				}
				else if(a==0){
					exit(0);
					break;
			}
				else{
					cout<<"Enter Correct Option "<<endl;
				}
			}

		}
		else{
			cout<<"No Quiz Is Present at Current TIme For Your Registered Courses..."<<endl;
			exit(0);
		}

		return "";
		
			

	}

	int takeAnswers(){
			ifstream inputFile("quiz.txt");
			string questions[MAX];
			string answers[MAX];
			string line;
			int index=0;

			
			while(getline(inputFile, line)){
				if(line.empty()){
					index++;;
				}
				else{
					questions[index]+=line+"\n";
				}
			}

				
				for(int i=0; i<index; i++){
					cout<<questions[i]<<endl;
					cout<<"Enter Your Answer : ";
					getline(cin>>ws, this->answers[i]);
				}
				return index;
		}

	void correctanswers(){
		ifstream AnswersFile("answers.txt");
		string correctans[MAX];
		string line;
		int index=0;

		
		while(getline(AnswersFile, line) && index<MAX){
			this->correctans[index]=line;
			++index;
		}

		
	}


	int calculateResult(int index){
		obtainedMarks=0;

		for(int i=0; i<index; i++){
			if(answers[i]==correctans[i]){
					obtainedMarks=obtainedMarks+5;		
			}

		continue;
	}
	cout<<"Obtained Marks : "<<obtainedMarks;

	cout<<endl;
	return obtainedMarks;
	}

	int calculateTotal(int index){
		totalMarks=index*5;
		cout<<"Total Marks : "<<totalMarks<<endl;
		return totalMarks;
	}


	

};


class Teacher{
private:
	string username;
	string pass;
	string course;

public:

	Teacher(){
		username=" ";
		pass=" ";
		course=" ";
	}

	Teacher(string username, string pass){
		this->username=username;
		this->pass=pass;
		course=" ";
	}

	
	string getusername(){
		return username;
	}

	string getpassword(){
		return pass;
	}

	string getcourse(){
		return course;
	} 

	void setusername(string username){
		this->username=username;
	}

	void setpassword(string pass){
		this->pass=pass;
	}

	void setcourse(string course){
		this->course=course;
	}



	string TeacherLogin(){

	string username=getusername();
	string password=getpassword();

	ifstream file("Teacher.csv");
	
	if(!file){
		return "Failed to open file.";
	}

	string line;
	
	while(getline(file, line)){
		stringstream ss(line);
		string temp;
	
		getline(ss, temp, ','); 
		
		if(temp==username){
			getline(ss, temp, ',');
	
				if(temp==password){
				getline(ss, temp, ',');
	
					if (!temp.empty()){
						    return temp;
							} 
						}
				}
			}

			return "Invalid Credientials";
		}

	
		
};


class Quiz{
private:
	string course;
public:
	
	Quiz(string course){
		this->course=course;
	}

	string getcourse(){
		return course;
	}

	bool GenerateQuiz(){

	string str=getcourse();
	string str1=".txt";
	str.append(str1);
	int a;
    int count = 0;
    string matchVariable;
    string line;
    bool startDisplay = false;

    int x;
    int y;
    int z;

    cout<<"How many MCQ's You Want"<<endl;
    cin>>x;
    
    matchVariable="2efcde9";
    
    
    
    ifstream inputFile(str);
    

    ofstream outputFile("quiz.txt");


    
	outputFile<<getcourse()<<endl;
    while (getline(inputFile, line)){


        if (line==matchVariable) {
            startDisplay=true;
        }
        else if(startDisplay && line.empty()) {
            startDisplay=false;
            
            count++;
            outputFile<<endl;
            if(count==x){
                break;
            }
            outputFile<<endl;
        }
        else if(startDisplay) {
            outputFile<<line<<endl;
        }
    }


    inputFile.close();
    outputFile.close();

    count=0;
    startDisplay=false;
    matchVariable=" ";

    cout<<"How many T/F : ";
    cin>>y;
    cout<<endl;

    matchVariable="b94d27b";

    ifstream inputFile1(str);
    
    ofstream outputFile1("quiz.txt", ios_base::app);
    

    

    while (getline(inputFile1, line)) {
        if (line==matchVariable) {
            startDisplay=true;
        }
        else if(startDisplay && line.empty()) {
            startDisplay=false;

            count++;
            outputFile1<<endl;
            if(count==y){
                break;
            }
            outputFile1<<endl;
        }
        else if(startDisplay) {
            outputFile1<<line<<endl;
        }
    }

    inputFile1.close();
    outputFile1.close();
    

    count=0;
    startDisplay=false;
    matchVariable=" ";

    cout<<"How many Descriptive : ";
    cin>>z;
    cout<<endl;

    matchVariable="88f7ace";

    ifstream inputFile2(str);
    

    ofstream outputFile2("quiz.txt", ios_base::app);
    

    

    while (getline(inputFile2, line)) {
        if (line==matchVariable) {
            startDisplay=true;
        }
        else if(startDisplay && line.empty()) {
            startDisplay=false;
            outputFile2<<endl;
            count++;

            if(count==z){
                break;
            }
            outputFile2<<endl;
        }
        else if(startDisplay) {
            outputFile2<<line<<endl;
        }
    }

    inputFile2.close();
    outputFile2.close();
	return true;
	}


	void ShowAnalytics(){
		ifstream file("Analytics.csv");  

		if(!file) {
			cout<<"ERROR$)$"<<endl;
			return;
		}

		string line;
		getline(file, line); 
		while ( getline(file, line)){
			string course, student, obtainedMarks, totalMarks;
			istringstream iss(line);
			getline(iss, course, ',');
			getline(iss, student, ',');
			getline(iss, obtainedMarks, ',');
			getline(iss, totalMarks, ',');

		if(course==this->getcourse()){
			cout<<"Student Name : "<<student<<endl;
			cout<<"Obtained Marks : "<<obtainedMarks<<endl;
			cout<<"Total Marks : "<<totalMarks<<endl;
			cout<<endl;
		}
		}

		file.close();
	}

}; 




int main(){

	menue1();
	
	return 0;
	}

void menue1(){
	cout<<"\t\t\t\t"<<"Welcome to Examination System"<<endl;
	cout<<"\t"<<"Made By AHMAD LUQMAN"<<endl;
	cout<<endl;
	int choice;
	cout<<"Press 1 For Teacher"<<endl;
	cout<<"Press 2 For Student"<<endl;
	cout<<"Press 0 to Quit"<<endl;

	while(1){
	cout<<"Your Option is : ";
	cin>>choice;
	cout<<endl;

	if(choice==1){
		teachermenu();
		break;
	}
	else if(choice==2){
		studentmenu();
		break;
		}
	else if(choice==0){
		exit(0);
	}
	
	else if(choice>=0 || choice<=9){
		cout<<"\t\t\t\t"<<"Enter Correct Option!!!"<<endl;
	}
	else{
		cout<<"\t\t\t\t"<<"Enter Correct Option!!!"<<endl;
	}
	}

	
}

void menuelogin(){
	string username;
	string password;

	cout<<"Enter Username : ";
	getline(cin>>ws,username);

	cout<<"Enter Password : ";
	cin>>password;
	cout<<endl;

	Login L(username, password);

	bool x;
	x=L.validate();
	cout<<endl;
	string y;
	int z=0;
	if(x){
		cout<<"\t\t\t\t"<<"LOGIN SUCCESSFULL!!!!"<<endl;
		cout<<"\t"<<"Welcome "<<username<<endl;
		cout<<endl;
		int x;
		cout<<"Press 1 to Display Registered Courses : "<<endl;
		cout<<"Press 2 to Go to Logout :  "<<endl;
		cout<<"Press 0 to Go to Main Menue : "<<endl;
		int totalmarks,obtmarks;
		
		while(1){
			cout<<"Your Choice is : ";
			cin>>x;
			cout<<endl; 
		if(x==1){
			Courses c;
			c.findname(L.getusername());
			c.displaycourses();
			c.Selectcourse();
			cout<<endl;
			y=c.checkQuiz();
			cout<<endl;
			z=c.takeAnswers();
			c.correctanswers();
			obtmarks=c.calculateResult(z);
			totalmarks=c.calculateTotal(z);
			cout<<endl;
			cout<<"Your Quiz Have been Successfully Submitted!!";
			cout<<endl;
			analytics(L.getusername(), obtmarks, totalmarks, y);
			break;
		}
		else if(x==0){
			menue1();
			break;
		}
		else if(x==2){
			menuelogin();
			break;
		}
		else{
			cout<<"\t\t\t\t"<<"Enter Correct Option!"<<endl;
		}
		}
		
		
	}
	else{	
		cout<<"Invalid Credientals OR User Not Registered.."<<endl<<endl;
		}
}

void teachermenu(){
	
	cout<<"Press 1 To Login"<<endl;
	cout<<"Press 2 To Quit"<<endl;
	cout<<endl;
	int x;
	while(1){
	cout<<"Your Option is : ";
	cin>>x;

	if(x==1){
		menueloginteacher();
		break;
	}
	else if(x==2){
		exit(0);
		break;
	}
	else{
		cout<<"Enter Correct Option : "<<endl;
	}

	}

}

void menueloginteacher(){
	string username;
	string password;
	cout<<endl;
	
	cout<<"Enter Your UserName : ";
	getline(cin>>ws, username);

	
	cout<<"Enter Your Password : ";
	getline(cin>>ws, password);

	cout<<endl;

	Teacher T(username, password);

	string x =T.TeacherLogin();

	if(x!="Invalid Credientials"){
		
		T.setcourse(x);
		cout<<"\t\t"<<"Welcome "<<username<<endl;
		cout<<endl;
		cout<<"\tYour Course Is : "<<T.getcourse()<<endl;
		quizmenu(x);

	}
	else{
		cout<<"Invalid Credientials";
	}

	
}

void quizmenu(string x){
	cout<<endl;
	cout<<"Press 1 to Generate Quiz for Your Course"<<endl;
	cout<<"Press 2 to See Analyics "<<endl;
	cout<<"Press 3 to Log Out."<<endl;
	cout<<"Press 4 to Go To Main Menue"<<endl;
	cout<<"Press 5 to Quit"<<endl;
	cout<<endl;
	int y;
	
	Quiz Q(x);


	while(1){
		cout<<"Your Choice is : ";
		cin>>y;
		cout<<endl;


		if(y==1){
			bool x=Q.GenerateQuiz();
			if(x){
			GenerateKey();
			RemoveMarker();
			break;
			}
			else{
				cout<<"Error $)$";
				exit(0);
			}
		}
		else if(y==2){
			Q.ShowAnalytics();
			break;
		}
		else if(y==3){
			menueloginteacher();
			break;
		}
		else if(y==4){
			menue1();
			break;
		}		
		else if(y==5){
			exit(0);
			break;
		}
		else{
			cout<<"Invalid Choice"<<endl;
		}
		

	}
}


char* generatepswrd(){

	char arr[]={'!', '@', '#', '$', '%', '^', '&', '*', '(', ')','a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z','A' ,'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'v', 'W', 'X', 'Y', 'Z'};
	

	char pass[6]={};

	int x=0;
	int i=0;
	srand(time(0));
	while(x<6)
	{
		
		i=rand()%62;

		pass[x]=arr[i];
		x++;
	}

	char *p=pass;

	return p;	
}

void studentmenu(){
		int x;
		cout<<"Press 1 if you are a New User and Want to Generate New Credientials."<<endl;
		cout<<"Press 2 to Login"<<endl;
		cout<<"Press 3 to Go To Main Menue"<<endl;
		cout<<"Press 0 to exit"<<endl;

		while(1){
		cout<<"Your Choice is : ";
		cin>>x;
		cout<<endl;
		
		if(x==1){
			Registration();
			break;
			}
		else if(x==2){
			menuelogin();
			break;
		}
		else if(x==3){
			menue1();
			break;
		}		
		else if(x==0){
			exit(0);
			break;
		}
		else{
			cout<<"\t\t\t\t"<<"Enter Correct Option..."<<endl;
		}
	}
		

}

void Registration(){
		string name;
		bool x;

	while(1){
		cout<<"Enter Name to Verify From List and Generate Credientials : ";
		getline(cin>>ws,name);
		cout<<endl;

		Login L(name);
		

		x=L.checkname();

		if(x){
			break;
		}
	}
		
		if(x){

			srand(time(0));
			char *ar=new char[6];
			char *p=generatepswrd();
			int i=0;
			
			while(i<6){
				ar[i]=p[i];
				i++;

			}
			string str(ar);
			delete []ar;
			ar=NULL;
			p=NULL;
			
		ofstream outfile;
		outfile.open("Users.csv", ios_base::app);
		outfile<<name<< "," <<str<<endl;
		outfile.close();
		
		cout<<"Password Generated Successfully"<<endl;
		cout<<"Your Password is : "<<str<<endl;

		int a;
		cout<<endl;
		cout<<"Press 1 to Login"<<endl;
		cout<<"Press 0 to Return to Main Menu"<<endl;

		while(1){
		cout<<"Your Choice is : ";
		cin>>a;
		cout<<endl;
		
		if(a==1){
			menuelogin();
			break;
		}
		else if(a==0){
			menue1();
			break;
		}
		else{
			cout<<"Enter Correct Option!!!!"<<endl;
		}
		}


			
		
		}
	
}

void GenerateKey(){
	ifstream inputFile("quiz.txt");
    ofstream outputFile("answers.txt");
    
    string line;
    string answer;
    
    while(getline(inputFile, line)){
        if(line.find("dabfac4")!=string::npos) {
            size_t markerPos=line.find("dabfac4:");
            if(markerPos!=string::npos) {
                answer=line.substr(markerPos+9); // Extract the answer after the marker
                outputFile<<answer<<endl; // Write the answer to the answers file
            }
        }
    }
    
    inputFile.close();
    outputFile.close();
    
    cout<<"Answer Key Generated Succesfully "<<endl;
	}



void RemoveMarker(){
		fstream file("quiz.txt", ios::in | ios::out); // Open the file for both reading and writing

    if(!file){
        cerr<<"Error opening the file."<<endl;
        return;
    }

    string line;
    stringstream updatedContents;

    while(getline(file, line)) {
        size_t markerPos = line.find("dabfac4");
        if(markerPos !=string::npos){
            line.erase(markerPos, 7); // Remove the marker "dabfac4:"
        }
        updatedContents<<line<<endl; // Store the modified line in a stringstream
    }

    file.clear(); // Clear the end-of-file flag
    file.seekp(0, ios::beg); // Move the write position to the beginning of the file
    file<<updatedContents.str(); // Write the modified contents back to the file

    file.close();

    cout<<"Marker has also been removed"<<endl;
	}



void analytics(string name, int obt, int total, string course){
	string fileName="Analytics.csv";
    ofstream file(fileName, ios_base::app);

    if(!file){
        cout<<"UNKNOWN ERROR $*$&$";
        return;
    }
    
    file<<course<<","<<name<<","<<obt<<","<<total<<endl;

    file.close();
}
