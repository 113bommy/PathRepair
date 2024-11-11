n,m,k = list(map(int,input().split()))
x,s = list(map(int,input().split()))
a_time = list(map(int,input().split()))
a_cost = list(map(int,input().split()))
b_num = list(map(int,input().split()))
b_cost = list(map(int,input().split()))

def binary_search(manapoints):
    global  k,b_cost
    l = 0;  r = k-1;  pos = -1
    while (l <= r):
        mid = int((l+r)/2)
        if (b_cost[mid] <= manapoints):
            l = mid+1;  pos = mid;
        else :
            r = mid-1
    return pos
res = n*x
pos = binary_search(s)
if (pos >= 0):  res = min(res,(n-b_num[pos])*x);
for i in range(m):
    if (a_cost[i] > x): continue;
    rest = s-a_cost[i]
    pos = binary_search(rest)
    if (pos >= 0):  res = min(res,(n-b_num[pos])*a_time[i])
    else : res = min(res,n*a_time[i])
print(res)