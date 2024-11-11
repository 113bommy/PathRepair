N=int(input())
A = list( map(int,input().split()))
C0 = [ [0,i] for i in range(100005) ]
C1 = [ [0,i] for i in range(100005) ]
for i in range(0,N,2):
    C0[A[i]][0] += 1
    C1[A[i+1]][0] += 1
C0.sort(reverse=True)
C1.sort(reverse=True)
if C0[0][1] == C1[0][1]:
    ans = N - max(C0[0][0]+C1[1][0], C0[1][0]+C1[0][0])
else:
    ans = N - C0[0][0] - C1[0][0]
print(ans)
