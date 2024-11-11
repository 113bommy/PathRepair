n,x,y=map(int,input().split());
an=[int (an) for an in input().split()]
count=0;
if(x>y):
    print(n);
elif(x<=y):
    for i in range(0,n):
        if an[i]<=x:
            count+=1;
    print(int(count+1/2));        
