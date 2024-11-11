n,t = map(int,input().split())
ma = 1001
for i in range(n):
    c,ti = map(int,input().split())
    if ti < t+1:
        if c< ma: ma=c
print(ma if ma !=1000 else"TLE")