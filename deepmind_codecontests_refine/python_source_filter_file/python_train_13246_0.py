t = int(input())
ans = []
for _ in range(t):
    N = int(input())
    S = list(map(int,input().split()))
    X = [1]*N
    for i in range(N):
        for j in range((i+1)*2,N,i+1):
            if(S[i] < S[j]):
                X[j] = max(X[j],X[i]+1)
    ans.append(max(X))   

for i in ans:
    print(i)