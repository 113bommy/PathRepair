a, b = map(int,input().split())
a=max(a, b)
b=min(a, b)
print(b, (a-b)//2)