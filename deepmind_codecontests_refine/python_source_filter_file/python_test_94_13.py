import math as m

def L():
    return list(map(int, input().split()))
def I():
    return int(input())

def solve():
    n,k = map(int, input().split())
    arr = L()
    
    ans = 0
    for i in range(n-1):
        if k > 0:
            x = 10**(arr[i+1] - arr[i])-1
            okok = min(x,k)
            ans += 10**arr[i] * okok
            k -= okok
    ans += k*10**arr[n-1]
    print(ans)

for _ in range(int(input())):
    solve()