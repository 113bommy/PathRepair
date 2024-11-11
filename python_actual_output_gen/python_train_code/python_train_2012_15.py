N,T=map(int,input().split())
l=[]
for i in range(N):
    c,t=map(int,input().split())
    if t < T:
        l.append(c)
if not l:
    print("TLE")
else:
    print(min(l))