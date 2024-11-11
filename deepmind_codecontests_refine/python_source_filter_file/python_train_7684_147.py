a,b = map(int,input().split())
t = b-a
print(t*(t-1)//2-b)