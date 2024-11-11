a,b=map(int,input().split())
print([a*b+a,-1][a%b==0])