n,a,b = map(int,input().split())
 
if (b-a)%2 == 0:
    print(int((b-a)/2))
else:
    print(min(a,n-b+1)+(b-a-1)//2)