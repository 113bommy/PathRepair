a,b = map(int,input().split())
print(max(a,b) + max(min(a,b),max(a,b)-1))