n,m = list(map(int,input().split()))
lst = list(map(int,input().split()))
if n < m:
    l = m
    h = 1
    while h<l//3:
        h+=3*h+1
    while h >=1:
        for i in range(h,l):
            for j in range(i,h-1,-h):
                if lst[j] < lst[j-h]:
                    lst[j], lst[j-h] = lst[j-h],lst[j]
        h//=4
    mini = 10000000
    for i in range(0,l,n):
        if len(lst[i:i+n]) == n:
            sumi =lst[i:i+n][-1] - lst[i:i+n][0]
        if sumi<mini:
            mini = sumi
    print(mini)
else:
    print(max(lst)-min(lst))
