from itertools import combinations
N = int(input())
K = 0
for i in range(2,N+2):
    if N==(i*(i-1))//2:
        K = i
        break
if K==0:
    print("No")
else:
    S = {i:[] for i in range(1,K+1)}
    cnt = 1
    for x in combinations(range(1,K+1),2):
        i,j = x
        S[i].append(cnt)
        S[j].append(cnt)
        cnt += 1
    print("Yes")
    print(K)
    for i in range(1,K+1):
        print(len(S[i]),*S[i])