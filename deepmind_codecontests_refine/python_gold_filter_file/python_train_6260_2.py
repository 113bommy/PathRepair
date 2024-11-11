def solve(a,n):
    x  = 0
    mat = [[0 for i in range(10**5)] for j in range(2)]
    res = 0
    odd = {}
    even = {0:1}
    for i in range(n):
        x  = x^a[i]
        if i%2==0:
            res += odd.get(x,0)
            odd[x] = odd.get(x,0) + 1
        else:
            res += even.get(x,0)
            even[x] = even.get(x,0) + 1
    return res

n = int(input())
a = list(map(int,input().split()))
print(solve(a,n))