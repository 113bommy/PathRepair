n,m = map(int,input().split())
set_ = set(range(1,n))
count_min = 0
for i in range(m):
    a = list(map(int,input().split()))
    if (a[0] == 2):
        set_ = set_ - {a[1]}
    else:
        set_ = set_ - {a[1]}
        set_ = set_ - {a[2]}
a = list(set_)
a.sort()
i = 0
while (i < len(a)):
    if (i+1 <= len(a)-1):
        if ((a[i]+1 - a[i]) == 1):
            count_min = count_min + 1
            i = i + 1
        else:
            count_min = count_min + 1
    else:
        count_min = count_min + 1
    i = i + 1
print(count_min,len(a))