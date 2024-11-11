N = int(input())
A = list(map(int, input().split()))
s = sum(A)
q, m = divmod(s, N*(N+1)//2)
if m != 0:
    print("NO")
    exit()
D = [A[i]-A[i-1]-q for i in range(N)]
for d in D:
    if d%N != 0:
        print("NO")
        exit()
print("YES")
