n,s = [int(x) for x in input().split()]
def check(x):
    y = list(str(x))
    ans = x
    for i in y:
        ans-=int(i)
    if (ans>=s):
        return True
    return False
    
ans = 0
l = 1
r = n
while(l<r):
    m = (l+r)//2
    if (check(m)):
        ans = n-m+1
        r = m-1
    else:
        l = m+1
print(ans)