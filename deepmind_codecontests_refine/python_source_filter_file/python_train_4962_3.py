n,a1,b1,c1,t=map(int,input().split())
r=list(map(int,input().split()))
if (c1<=b1):
      print(n*a1)
else:
      s=0
      for i in r:
            s+=(c1-b1)*(n-i)
      print(s+n*a1)  
#pilotezebi
 
