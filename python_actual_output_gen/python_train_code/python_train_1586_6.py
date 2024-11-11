a,b,m=map(int, input().split())
A=list(map(int, input().split()))
B=list(map(int, input().split()))
buf=min(A)+min(B)
for i in range(m):
    x,y,c=map(int, input().split())
    cp=A[x-1]+B[y-1]-c
    if buf>=cp:
        buf==cp
print(buf)