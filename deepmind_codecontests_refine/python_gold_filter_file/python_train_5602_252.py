(a,b) = map(int,input().split())
print(max(a,b)+max(max(a,b)-1,min(a,b)))