def f(x):
    now = 0
    for i in range(n):
        now += (a[i]-1)//x

    return now <= k

n, k = map(int, input().split())
a = list(map(int, input().split()))
ng = 0
ok= int(1e9)
while ok - ng > 1:
    x = (ok + ng) // 2
    if f(x):
        ok = x
    else:
        ng = x

print(ok)