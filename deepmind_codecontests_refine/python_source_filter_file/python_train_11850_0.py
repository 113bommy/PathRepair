N ,M = map(int,input().split())
L = []
ans = 0
for i in range(1,int(M**(1/2)+1)):
    if M % i == 0:
        if i >= N: ans = max(ans,i)
        if M // i >= N: ans = max(ans,M//i)
print(ans)
