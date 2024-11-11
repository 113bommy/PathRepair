a,b=map(int,input().split())
e=2000
for i in range(a):
    c,d=map(int, input().split())
    if d<=b:
        e=min(e,c)
print(e if e!=2000 else "TLE")