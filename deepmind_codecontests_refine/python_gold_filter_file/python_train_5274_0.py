n,U=list(map(int, input().split(' ')))
a=list(map(int, input().split(' ')))

import bisect
def max_eligible(a,x):
    ind=bisect.bisect_right(a,x)
    if ind <= len(a):
        return a[ind-1]
    else:
        return -1

max_val=-1
for i in range(n-2):
    x = a[i]+U
    val1 = max_eligible(a,x)

    if val1!=-1 and val1!=a[i+1] and val1!=a[i]:
        # print('hi')
        val = (val1-a[i+1]) / (val1-a[i])
        # print(val)
        max_val=max(max_val,val)
    # print(a[i],a[i+1],val1,max_val)
print(max_val)
