N=int(input()) 
l = list(map(int,input().split())) 
if(min(l)==1):
 print(-1) 
else:
 print(min(l) -1) 