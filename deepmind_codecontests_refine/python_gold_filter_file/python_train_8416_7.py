n,x=map(int,input().split())
A=list(map(int,input().split()))
C=A[:]
s2=0
for i in range(n-1):
    v=C[n-1-i]+C[n-2-i]
    if v>x:
        s2+=v-x
        C[n-2-i]=0 if x<=C[n-1-i] else x-C[n-1-i]
print(s2)