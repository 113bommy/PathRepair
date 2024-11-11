n,T=map(int,input().split())
C=1001
for i in range(n):
    c,t=map(int,input().split())
    if T>=t:
        C=min(c,C)
print(C if C<1001 else "TLE")