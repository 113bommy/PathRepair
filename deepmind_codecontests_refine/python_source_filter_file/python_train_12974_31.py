n,t=map(int,input().split())
A=list(map(int,input().split()))
D=86400
for i in range(n):
    if D-A[i]>t:
        print(i+1)
        break
    else:
        t-=(D-A[i])
    