N = int(input())
A = {}

MAX = 0
for i in range(N):
    s = input()
    A[s] = A.get(s,0) + 1
    MAX = max(MAX, A[s])

B = sorted(A.items())
print(B)
for k, v in B:
    if v == MAX:
        print(k)