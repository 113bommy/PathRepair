a,b = map(int,input().split())
print(min(a,b),((a-min(a,b))+(b-min(a,b)))//2)