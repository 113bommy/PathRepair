a,b=map(int,input().split())
print([-1,a*b+a][a%b==0])