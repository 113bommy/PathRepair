a,b = tuple(map(int,input().split()))

print(max(a+a-1,a+b,b+b-1))