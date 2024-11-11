n,k = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

def func(x):
    global n,k
    cnt = 0
    for i in range(n):
        cnt += max(0,(a[i] * x) - b[i])
    if(cnt > k):
        return False
    return True

lb = 0
ub = 2*(1**9) + 1
while(lb < ub):
    mid = (lb + ub + 1) // 2
    if(func(mid)):
        lb = mid
    else:
        ub = mid  - 1
        
print(lb)