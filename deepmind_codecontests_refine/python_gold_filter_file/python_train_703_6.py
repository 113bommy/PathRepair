f=lambda:map(int,input().split())
N,M=f()
q=[list(f()) for _ in [0]*M]
res=-1
A=list(range(10**(N-1),10**N))
if N==1:A=[0]+A
for i in A:
    for j in range(M):
        if str(i)[q[j][0]-1]!=str(q[j][1]):
            break
    else:
        res=i
        break
print(res)