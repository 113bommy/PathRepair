N,T=map(int, input().split())
C=[]
for n in range(N):
    c,t=map(int,input().split())
    if t<=T:
        C.append(c)
if not C:
    print("TLE")
else:
    print(min(C))