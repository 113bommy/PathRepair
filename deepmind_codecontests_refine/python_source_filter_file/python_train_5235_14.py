t = int(input())
for _ in range(t):
    n,k = tuple(map(int,input().split(' ')))
    a = list(map(int,input().split(' ')))
    a.sort(reverse=True)
    ans = a[0]+a[1]
    print(ans)