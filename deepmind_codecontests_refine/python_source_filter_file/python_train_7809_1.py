def ascend(a,b):
    mini = min(A[a:a+L])
    ans[a] = mini
    for i in range(a+1,b):
        if A[i+L-1] <= mini : mini = A[i+L-1]
        elif A[i-1] == mini : mini = min(A[i:i+L])
        ans[i] = mini

def descend(a,b):
    mini = min(A[b-1:b+L-1])
    ans[b-1] = mini
    for i in range(b-2,a-1,-1):
        if A[i] <= mini : mini = A[i]
        elif A[i+L] == mini: mini = min(A[i:i+L])
        ans[i] = mini
    
[N,L] = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
ans = [None]*(N-L+1)
count = 0;
if N > 10 ** 4:
    for i in range(100):
        if A[i+1] > A[i] : Pcount += 1
    if Pcount > 80 : descend(0, N-L+1)
    else : ascend(0,N-L+1)
else :
    ascend(0, N-L+1)
for i in ans[:-1] : print(i, end=" ")
print(ans[-1])