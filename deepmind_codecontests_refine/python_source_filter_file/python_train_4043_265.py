a,b,c=map(int,input().split())
print(["NO","YES"][c-a<0 or c-a>b])