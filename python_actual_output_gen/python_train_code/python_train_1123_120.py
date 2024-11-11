a,b,x = map(int, input().split())
print(b//x-max(0, a-1)//x)