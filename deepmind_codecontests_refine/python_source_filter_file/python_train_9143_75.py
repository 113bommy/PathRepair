a,b,c,d =map(int,input().split())

answer = min(b,c) - max(a,c)
print(max(0,answer))