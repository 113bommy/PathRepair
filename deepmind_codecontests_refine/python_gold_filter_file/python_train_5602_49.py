a,b = map(int,input().split())
print(max(a,b)+min(max(a-1,b),max(a,b-1)))