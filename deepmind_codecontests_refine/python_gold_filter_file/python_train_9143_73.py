
a,b,c,d =map(int,input().split())

answer = min(b,d) - max(a,c)
print(max(0,answer))
