	#include<iostream>
	#include<math.h>
	using namespace std;
	int make(int *board)
	{
	  	int i;
		if(board[5]==2)
		{
			return 5;
		}
		else
		{
			for(i=2;i<9;i=i+2)
			{
				if (board[i]==2)
				{
					return i;
				}
			}
		}
		if(i==10)
		{
			return -1;
		}
	}

	int go(int sq,int turn,int *board)
	{
	 	if(turn%2==0)
	 	{
	 		board[sq]=5;
	 	}
		 else
	 	{
	 		board[sq]=3;
	 	}
	}
	
	int pwin(int *board,char p)
	{
		int i;int a[9],temp[9],t[9],j,k,l;
		j=1;
		if(p=='X')
		{
			l=3;
		}
		else
		{
			l=5;
		}
		temp[1]=8;temp[2]=3;temp[3]=4;temp[4]=1;temp[5]=5;temp[6]=9;
		temp[7]=6;temp[8]=7;temp[9]=2;
		t[1]=4;t[2]=9;t[3]=2;t[4]=3;t[5]=5;t[6]=7;t[7]=8;t[8]=1;t[9]=6;
		
		for(i=1;i<=9;i++)
		{
			a[i]=0;
		}
		
		for(i=1;i<=9;i++)
		{
			if(board[i]==l)
			{
				a[j]=i;j++;
			}
		}
	
		for(i=1;i<j;i++)
		{
			for(k=i+1;k<j;k++)
			{
				if(((15-(temp[a[i]]+temp[a[k]]))>=1)&&((15-(temp[a[i]]+temp[a[k]]))<=9)
				&&(board[t[15-(temp[a[i]]+temp[a[k]])]]==2))
			{
				return t[(15-(temp[a[i]]+temp[a[k]]))];
			
	    	}
			}
		}
		return 0;
	
	}

	void display(int *board)
	{
		char p;int i,j,k;
		for(i=1;i<=7;i+=3)
		{
			for(j=0;j<=2;j++)
			{
				if(board[i+j]==2)
				{
					 p=' ';
				}
				else if(board[i+j]==3)
				{
					p='X';
				}
				else
				{
					p='O';
				}
				cout<<" "<<p;
				if(j%3!=2)
				{
					cout<<" |";
				}
			}
			if(i!=7)
			{
				cout<<"\n___________\n";
			}
		}
		cout<<"\n";
	}
   
	int win(int *board,char p)
	{
    	int j,i;
    	if(p=='X')
	    {
			j=3;
		}
	   else
	   {
	     	j=5;
		}
	    for( i=1;i<=7;i+=3)
    	{
	       if((board[i]*board[i+1]*board[i+2])==pow(j,3))
	       {
		      return 1;
        	}
		}
		for(int i=1;i<=3;i+=1)
		{
			if((board[i]*board[i+3]*board[i+6])==pow(j,3))
			{
				return 1;
			}
		}
	 	if(board[1]*board[5]*board[9]==pow(j,3))
	 	{
	 		return 1;
	 	}
	 	else if(board[3]*board[5]*board[7]==pow(j,3))
	 	{
		 	return 1;
		}
		else
		 	return 0;
	}

	void user(int *board,int turn)
	{
		int p,v,c;v=0;
		if(turn%2==0)
		{
			c=5;
		}
		else
		{
			c=3;
		}
		do
		{
			cout<<"Enter your move (Square position no.):\n";
			cin>>p;
			if(p<1||p>9||board[p]!=2)
			{
				cout<<"invalid move\n";
			}
			else
			{
				board[p]=c;v=1;
			}
		}while(v!=1);
	}
	
	void computer(int *board,int turn)
	{
		int i;
		switch(turn)
		{
			case 1:
				go(1,turn,board);
				break;
			case 2:
				if(board[5]==2)
				{
					go(5,turn,board);
				}
				else
				{
					go(1,turn,board);
				}
				break;
			case 3:
				if(board[9]==2)
				{
					go(9,turn,board);
				}
				else
				{
					go(3,turn,board);
				}
				break;
			case 4:
				if(pwin(board,'X')!=0)
				{
					go(pwin(board,'X'),turn,board);
				}
				
				else if(board[2]==3 && board[4]==3)
		       {
					go(1,4,board);
				}
				else if(board[2]==3 && board[6]==3)
				{
					go(3,4,board);
				}
				else if(board[8]==3 && board[4]==3)
				{
					go(7,4,board);
				}
				else if(board[8]==3 && board[6]==3)
				{
					go(9,4,board);
				}
				
				else if(board[1]==3 && board[8]==3)
				{
					go(7,4,board);
				}
				else if(board[3]==3 && board[8]==3)
				{
					go(9,4,board);
				}
				else if(board[9]==3 && board[2]==3)
				{		
					go(3,4,board);
				}
				else if(board[7]==3 && board[2]==3)
				{
					go(1,4,board);
				}	
				else if(board[3]==3 && board[4]==3)
				{
					go(1,4,board);
				}
				else if(board[1]==3 && board[6]==3)
				{
					go(3,4,board);
				}
				else if(board[6]==3 && board[7]==3)
				{
					go(9,4,board);
				}
				else if(board[4]==3 && board[9]==3)
				{
					go(7,4,board);
				}
				
				else if(board[5]==3 && board[9]==3)
				{
					go(3,4,board);
				}
				else
				{
					go(make(board),turn,board);
				}
				break;
			case 5:
				if(pwin(board,'X')!=0)
				{
					go(pwin(board,'X'),turn,board);
				}
				else if(pwin(board,'O')!=0)
				{
					go(pwin(board,'O'),turn,board);
				}
				else
				{
					if(board[7]==2)
					{
						go(7,turn,board);
					}
					else
					{
						go(3,turn,board);
					}
				}
				break;
			case 6:
				if(pwin(board,'O')!=0)
				{
					go(pwin(board,'O'),turn,board);
				}
				else if(pwin(board,'X')!=0)
				{
					go(pwin(board,'X'),turn,board);
				}
				else
				{
				    if(make(board)!=-1)
					{
						go(make(board),turn,board);
				    }
				    else
				    {
				    	for(i=1;i<=9;i++)
				    	{
				    		if(board[i]==2)
				    		{
				    			go(i,turn,board);
				    			break;
							}
						}
					}
				}
				break;
			case 7:
				if(pwin(board,'X')!=0)
				{
					go(pwin(board,'X'),turn,board);
				}
				else if(pwin(board,'O')!=0)
				{
					go(pwin(board,'O'),turn,board);
				}
				else
				{
					for(i=1;i<=9;i++)
				    {
						if(board[i]==2)
				    	{
				    		go(i,turn,board);
				    		break;
						}
				    }
				}
				break;
			case 8:
				if(pwin(board,'O')!=0)
				{
					go(pwin(board,'O'),turn,board);
				}
				else if(pwin(board,'X')!=0)
				{
					go(pwin(board,'X'),turn,board);
				}
				else
				{
					for(i=1;i<=9;i++)
				    {
						if(board[i]==2)
				    	{
				    		go(i,turn,board);
				    		break;
				    	}
					}
				}
			    break;
			case 9:
				if(pwin(board,'X')!=0)
				{
					go(pwin(board,'X'),turn,board);
				}
				else if(pwin(board,'O')!=0)
				{
					go(pwin(board,'O'),turn,board);
				}
				else
				{
					for(i=1;i<=9;i++)
				    {
				    	if(board[i]==2)
				    	{
				    		go(i,turn,board);
				    		break;
						}
					}
				}
				break;
		}
	}

	int main()
	{
		int *board,turn;
		int o=0;
		board=new int[9];
		int i; char j,K;
		for(i=1;i<=9;i++)
		{
			board[i]=2;
		}
		do
		{
 			cout<<"Do you want to play first(y/n):\n";
			cin>>K;
		}while(K!='y'&&K!='Y'&&K!='N'&&K!='n');
		display(board);
		if(K=='y'||K=='Y')
		{
			j='O';
		}
		else
		{
			j='X';
		}
		turn=1;
		while(turn<=9)
		{
			if(j=='X')
			{
				cout<<"\n---------\n"<<"computer's move:\n";
				computer(board,turn);
				display(board);
				turn++;
				if((turn>=5)&&(win(board,'X')==1))
				{
					cout<<"\n---------\n";
					cout<<"Sorry! Computer won this Game...better luck next time\n";
					o=1;
					break;
				}
				if(turn<10)
				{
					cout<<"\n---------\n"<<"user's move:\n";
					user(board,turn);
					display(board);
					turn++;
					if((turn>=5)&&(win(board,'O')==1))
					{
						cout<<"\n---------\n";
						cout<<"Hurray ! Human Won\n";
						o=1;
						break;
					}
			    }
			}
			else
			{
				cout<<"\n---------\n"<<"Human's move:\n";
				user(board,turn);
				display(board);
				turn++;
				if((turn>=5)&&(win(board,'X')==1))
				{
					cout<<"\n---------\n";
					cout<<"Hurray ! Human Wonn\n";
					o=1;
					break;
				}
				if(turn<10)
				{
					cout<<"\n---------\n"<<"computer's turn:\n";
					computer(board,turn);
					display(board);
					turn++;
					if((turn>=5)&&(win(board,'O')==1))
					{
						cout<<"\n---------\n";
						cout<<"Sorry! Computer won this Game...better luck next time\n";
						o=1;
						break;
					}
				}
			}
		}
		if((turn>=10)&&(o==0))
		{
			cout<<"\n---------\n";
			cout<<"Draw";
		}
		return 0;
	}

