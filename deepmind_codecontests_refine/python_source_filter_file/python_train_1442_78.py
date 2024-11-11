a,b,c=map(int,input().split())
print(["NO","YES"][(b*10+c)%4==0]