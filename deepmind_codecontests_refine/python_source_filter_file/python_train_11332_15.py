N, M = list(map(int, input().split()))
A = [input() for i in range(N)]
B = [input() for i in range(M)]

ans = "No"

for i in range(N-M+1):
    for j in range(N-M+1):
        t = [k[j:j+M] for k in A[i:i+M]]
    if t == B:
        ans = "Yes"
 
print(ans)
