import sys
input = lambda : sys.stdin.readline().rstrip()
sys.setrecursionlimit(max(1000, 10**9))
write = lambda x: sys.stdout.write(x+"\n")

n = int(input())
a = list(map(int, input().split()))

unit = n*(n+1)//2
k, m = divmod(sum(a), unit)
if m:
    ans = "NO"
else:
    count = [None] * n # iを選んだ回数
    for i in range(n):
        diff = a[i] - a[i-1]
        x, m = divmod(k- diff, n)
        if m:
            ans = "NO"
            break
        count[i-1] = x
    else:
        if sum(count)==k and sum(c*(n-i) for i,c in enumerate(count)):
            ans = "YES"
        else:
            ans = "NO"
print(ans)