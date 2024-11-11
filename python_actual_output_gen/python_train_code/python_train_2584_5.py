N, Q = map(int,input().split())
S = input()
memo = [0 for _ in [0]*(N+1)]
for i in range(2,N+1):
    memo[i] = memo[i-1] + int(S[i-2:i]=="AC")
for _ in range(Q):
    l, r = map(int,input().split())
    print(memo[r]-memo[l-1])