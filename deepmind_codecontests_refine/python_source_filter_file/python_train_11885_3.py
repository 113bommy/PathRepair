n,m=[int(i) for i in input().split(" ")]
a=[]
for i in range(m):
    a.append([int(i) for i in input().split(" ")])
for i in a[0],a[1]:
    myset=set(i for i in range(1,n+1))
    for x in a[1:]:
        if i not in x:
            myset.intersection_update(set(x))
    if len(myset):
        exit(print("YES"))
print("NO")