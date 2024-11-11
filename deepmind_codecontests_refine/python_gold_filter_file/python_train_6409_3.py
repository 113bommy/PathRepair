from bisect import bisect_right

def find_le(a, x):
    'Find rightmost value less than or equal to x'
    i = bisect_right(a, x)
    if i:
        return i-1
    return -3

n,m,k = list(map(int,input().split()))
x,s = list(map(int,input().split()))
a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = list(map(int,input().split()))
d = list(map(int,input().split()))
ans = 10**30

for i in range(m):
    if b[i] > s:
        continue

    mana = s-b[i]
    ind = find_le(d,mana)
    if ind == -3:
        ans_i = a[i]*n
    else:
        ans_i = a[i]*max(0,n-c[ind])
    if ans_i < ans:
        ans = ans_i

mana = s
ind = find_le(d,mana)
if ind == -3:
    ans_i = x*n
else:
    ans_i = x*max(0,n-c[ind])
if ans_i < ans:
    ans = ans_i

print(ans)