n = int(input())
v = list(map(int, input().split(" ")))
u = list(v)
u.sort()
sv, su = [v[0]], [v[0]]
for i in range(1, n):
    sv.append(v[i] + sv[i-1])
    su.append(u[i] + su[i-1])
sv.append(0)
su.append(0)
m = int(input())
for i in range(m):
    [t, l, r] = list(map(int, input().split(" ")))
    l, r = l-1, r-1
    if t == 1:
        print(sv[r] - sv[l-1])
    else:
        print(su[r] - su[l-1])
