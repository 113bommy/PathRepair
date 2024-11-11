a,b=map(int, input().split())
print(max(a,b)+max(max(a-1,b),max(b-1,a)))