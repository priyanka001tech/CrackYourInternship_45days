class Solution 
{
    public:
	int minStepToReachTarget(vector<int>&K,vector<int>&T,int n)
	{
	    int x1=K[0];
	    int y1=K[1];
	    int x2=T[0];
	    int y2=T[1];
	    
	    if(x1==x2 and y1==y2){
	        return 0;
	    }
	    int a[1001][1001];
	    for(int i=0;i<1001;i++){
	        for(int j=0;j<1001;j++){
	            a[i][j]=0;
	        }
	    }
	    queue<pair<int,int>>q;
	    q.push(make_pair(x1-1,y1-1));
	    while(!q.empty()){
	        auto temp=q.front();
	        int i=temp.first;
	        int j=temp.second;
	        q.pop();
	        
	        if((i-1)>=0 and (i-1)<n and (j-2)>=0 and (j-2)<n and a[i-1][j-2]==0){
	            a[i-1][j-2]=a[i][j]+1;
	            q.push(make_pair(i-1,j-2));
	        }
	        if((i+1)>=0 and (i+1)<n and (j-2)>=0 and (j-2)<n and a[i+1][j-2]==0){
	            a[i+1][j-2]=a[i][j]+1;
	            q.push(make_pair(i+1,j-2));
	        }
	        if((i-1)>=0 and (i-1)<n and (j+2)>=0 and (j+2)<n and a[i-1][j+2]==0){
	            a[i-1][j+2]=a[i][j]+1;
	            q.push(make_pair(i-1,j+2));
	        }
	        if((i+1)>=0 and (i+1)<n and (j+2)>=0 and (j+2)<n and a[i+1][j+2]==0){
	            a[i+1][j+2]=a[i][j]+1;
	            q.push(make_pair(i+1,j+2));
	        }
	        if((i-2)>=0 and (i-2)<n and (j-1)>=0 and (j-1)<n and a[i-2][j-1]==0){
	            a[i-2][j-1]=a[i][j]+1;
	            q.push(make_pair(i-2,j-1));
	        }
	        if((i-2)>=0 and (i-2)<n and (j+1)>=0 and (j+1)<n and a[i-2][j+1]==0){
	            a[i-2][j+1]=a[i][j]+1;
	            q.push(make_pair(i-2,j+1));
	        }
	        if((i+2)>=0 and (i+2)<n and (j-1)>=0 and (j-1)<n and a[i+2][j-1]==0){
	            a[i+2][j-1]=a[i][j]+1;
	            q.push(make_pair(i+2,j-1));
	        }
	        if((i+2)>=0 and (i+2)<n and (j+1)>=0 and (j+1)<n and a[i+2][j+1]==0){
	            a[i+2][j+1]=a[i][j]+1;
	            q.push(make_pair(i+2,j+1));
	        }
	    }
	    return a[x2-1][y2-1];
	}
};
