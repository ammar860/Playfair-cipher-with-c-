                                     // PROJECT BY NOMAN AND AMMAR
                                    // CLASS =22 BRAVO
                                   // SUBMITTED TO = SIR WALEED BIN SHAHID
                      
#include<iostream>
#include<cstring>
using namespace std;

char encryption(char pt[]);          // function for encry
char decryption(char pt[]);            // function for decry
void playfair();
char key[100],play[5][5],ct[500],msg[500];      // global variables

int main()
{
	system("color 4e");
    system("color 3d");
	char ecpvalue;
	char dvalue;
	int i,choice,flag=0,j,k,size;
	cout<<"\t\t NOMAN AND AMMAR PROJECT \n\n";
	cout<<"\n\t\t --- play Fair Cipher ---\n";
	cout<<"Enter plain text :"<<endl;
	gets(msg);


	size=strlen(msg);

	int count = 0;                                      
	                                
	for (i = 0; msg[i]; i++)           //this for loop is to remove space between text
	{                                          
		if (msg[i] != ' ')
		{
			msg[count++] = msg[i];                 
		}
	}
	msg[count] = '\0';                

	size = count;
	
	cout<<"Spaces Removed:  \n"<<msg<<endl;
	
	
	for(i=0;i<size;i++)
	{
		if(msg[i]==msg[i+1])
		{
			for(j=size;j>i;j--)
			{
				msg[j]=msg[size-1];
				size--;
			}
			if(size!=0)
			{
				msg[j+1]='x';
			}
		}
	}


	size=strlen(msg);          //  if text is odd then this if statement is used to make it even by adding x    
	if(size%2!=0)
	{
		msg[size]='x';
		msg[size+1]='\0';
	}
		cout<<"\n message for encryption is : ";
	for(i=0;msg[i];i++)            //create space after two characters according to playfair algo
	{
		putchar(msg[i]);
		if(i%2!=0)
		{
			cout<<"  ";
		}
	}
	
	

	 char what;
    
    do{                  // this do while loop is used to ask user for their choice to perform encry and decry
	cout<<"\npress a for encryption\npress b for decryption\npress 'c' for exit\n";             
	cin>>what;
	switch(what)
	{
	
	case 'a':
		{
		

	ecpvalue = encryption(msg);
	cout<<ecpvalue;
	flag=1;}
	break;
	
	
     case 'b':
           if(flag==1){
		   
		   
         dvalue = decryption(ct);
		 cout<<dvalue;}
else cout<<"first perform encryption process";
break;
	
	

     case 'c' :
	
	  cout<<" exist"; 
	  break;
	default:
	
		cout<<"invalid command";
			break;
	
}
}
while(what!=0);
}




char encryption(char pt[])

  
{

	int k,l,row1=0,row2=0,col1=0,col2=0,p=0,q=0;
	cout<<"\n plane text="<<pt;
	
	playfair();


	for(int i=0,j=1;i<strlen(pt);i=i+2,j=j+2)
	{
	
		p=pt[i];
		q=pt[j];
		cout<<"\t ";
	    putchar(pt[i]); 
		putchar(pt[j]);
		cout<<"= ";
		if(p=='j')
		{ 
			pt[i]='i';
		}
		if(q=='j')
		{ 
			pt[i]='i';
		}
		for(int k=0;k<5;k++)
		{
			for(l=0;l<5;l++)
			{
				if(play[k][l]==p)
				{ 
					row1=k;
					col1=l;
				}
				if(play[k][l]==q)
				{
					row2=k;
					col2=l;
				}
			}
		}                           // these three if else statments are basically   are main algo of play fair
		if(row1==row2)
		{
			ct[i]=play[row1][(col1+1)%5];                   // for same row
			ct[j]=play[row2][(col2+1)%5];
			putchar(ct[i]);
			putchar(ct[j]);
		}
		else if(col1==col2)                            // for same column
		{
			ct[i]=play[(row1+1)%5][col1];
			ct[j]=play[(row2+1)%5][col2];
			putchar(ct[i]);
			putchar(ct[j]);
		}
		else
		{
			ct[i]=play[row1][col2];
			ct[j]=play[row2][col1];                // if alphabets are not in same col  and row  
			putchar(ct[i]);
			putchar(ct[j]);
		}
		
	}
	
	cout<<"\n \tEncrypted msg is = "<<ct;
}

char decryption(char pt[])
{
	int l,row1=0,row2=0,col1=0,col2=0,p=0,q=0;
	cout<<"\n plane text="<<pt;

	
 playfair();
 

	for(int i=0,j=1;i<strlen(pt);i=i+2,j=j+2)
	{
	
		p=pt[i];
		q=pt[j];
		cout<<"\t ";
	    putchar(pt[i]); 
		putchar(pt[j]);
		cout<<"= ";
		if(p=='j')
		{ 
			pt[i]='i';
		}
		if(q=='j')
		{ 
			pt[i]='i';
		}
		for(int k=0;k<5;k++)
		{
			for(l=0;l<5;l++)
			{
				if(play[k][l]==p)
				{ 
					row1=k;
					col1=l;
				}
				if(play[k][l]==q)
				{
					row2=k;
					col2=l;
				}
			}
		}                           // these three if else statments are basically are main algo of play fair
		if(row1==row2)
		{
			ct[i]=play[row1][(col1+4)%5];                   // for same row
			ct[j]=play[row2][(col2+4)%5];
			putchar(ct[i]);
			putchar(ct[j]);
		}
		else if(col1==col2)                            // for same column
		{
			ct[i]=play[(row1+4)%5][col1];
			ct[j]=play[(row2+4)%5][col2];
			putchar(ct[i]);
			putchar(ct[j]);
		}
		else
		{
			ct[i]=play[row1][col2];           // if alphabets are not in same col  and row  
			ct[j]=play[row2][col1];
			putchar(ct[i]);
			putchar(ct[j]);
		}
		
	}
	
	cout<<"\n\n \tdecrypted msg is ="<<ct;
}

void  playfair()
{
	int i,k,j,size;
      cout<<"\n enter key : ";
	 cin>>key;
     
	strcat(key,"abcdefghiklmnopqrstuvwxyz");                  // concentration of key
	 
	size=strlen(key);
	for(i=0;i<size;i++)
	{
		if(key[i]=='j')                                 // if key= j then its key=i
		  { key[i]='i';
		  
		  }
		for(j=i+1;j<size;)
		{
			if (key[j] == key[i])                         
			{
				for (k = j; k < size; k++)        
				
			    {
			   
					key[k] = key[k + 1]; 
				}
			 size--;
			}
			else j++;
		}
	}

	for(i=0,k=0;i<5;i++)
	{                                     //generate play fair cipher block 5*5
		for(j=0;j<5;j++)
		{
			
			play[i][j]=key[k];
			k++;
			
		}
	}
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{ 
			cout<<" ";
			 putchar(play[i][j]); 
		}
		cout<<"\n\n";
	}
}

                                                     // [THE END ]
