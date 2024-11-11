N, Q = map(int, input().split())
S = input()
A = [0, 0]
c = 0
for i in range(1,N):
    if S[i-1:i+1] == "AC":
        c += 1
    A.append(c)
print(A)
for _ in range(Q):
    l, r = map(int, input().split())
    print(A[r]-A[l])