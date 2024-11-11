t = int(input())
while t:
    nkz = list(map(int,input().rstrip().split()))
    n = nkz[0]
    k = nkz[1]
    z = nkz[2]
    a = list(map(int,input().rstrip().split()))
    res = 0
    for left in range(min(z+1,k//2)):
        ans = 0
        max_pair = 0
        for i in range(k + 1 - 2*left):
            ans += a[i]
            if i != k:
                max_pair = max(max_pair,a[i] + a[i+1])
        res = max(res,ans + (max_pair*left))
    print(res) 
    t -= 1