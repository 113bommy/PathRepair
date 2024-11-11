N = int(input())
A,B = [],[]
for _ in range(N):
    a,b = map(int,input().split())
    A.append(a)
    B.append(b)
if A == B:
    print(0)
    exit()
ans = 0
for i in range(N):
    if B[i] < A[i]:
        ans = min(ans,-B[i])
print(sum(B) + ans)
        
