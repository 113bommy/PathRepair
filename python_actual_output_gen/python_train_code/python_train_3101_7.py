x,y=map(int,input().split())
print("Yes") if ((x-y)%2==1 and (x-y)>-2 and y!=0) or (y==1 and x==0) else print('No')