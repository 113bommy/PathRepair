a,b,c,d = map(int,input().split())
e = max(a,c)
f = min(b,d)

print(min(0,f-e))