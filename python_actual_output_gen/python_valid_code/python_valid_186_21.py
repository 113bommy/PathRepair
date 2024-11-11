N,M,K = map(int,input().split())
A = list(map(int,input().split()))
B = list(map(int,input().split()))
AX = [0];BX = [0]

for a in A:
    AX.append(AX[-1]+a)
for b in B:
    BX.append(BX[-1]+b)    

ans = 0
j = M
for i in range(1,N+1):
    if AX[i] > K:
        break
    while AX[i]+BX[j] > K:
        j -= 1
    ans = max(ans,i+j)
print(ans)
