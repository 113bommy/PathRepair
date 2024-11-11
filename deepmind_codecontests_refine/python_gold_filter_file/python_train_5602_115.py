a,b=map(int,input().split())
print(max(a+b,max(a,b)+max(a-1,b-1)))
