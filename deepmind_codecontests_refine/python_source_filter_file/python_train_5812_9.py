n,T=map(int,input().split())
C=1000
for i in range(n):
    c,t=map(int,input().split())
    if T>=t:
        C=min(c,C)
print(C if C<1000 else "TLE")