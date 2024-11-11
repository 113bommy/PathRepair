
from bisect import bisect_right as bi

n = int(input())

mn_a = []
mx_a = []
ans = n**2

for i in range(n):
    inp = list(map(int, input().split()))
    l = inp[0]
    ss = inp[1:]
    not_asc = True
    for j in range(l-1):
        if(ss[j] < ss[j+1]):
            not_asc = False
            break

    if(not_asc or l==1):
        mn_a.append(ss[-1])
        mx_a.append(ss[0])

mn_a.sort()
mx_a.sort()

for i in range(len(mn_a)):
    ans -= bi(mx_a, mn_a[i])

print(ans)
