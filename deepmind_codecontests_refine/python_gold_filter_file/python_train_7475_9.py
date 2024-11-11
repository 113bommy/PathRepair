N,Q = map(int, input().split())
S = input()

t = [0] * (N+1)
for i in range(N):
    t[i] = t[i-1] + (1 if S[i:i+2] == "AC" else 0)
for i in range(Q):
    l,r = map(int, input().split())
    print(t[r-2] - t[l-2])