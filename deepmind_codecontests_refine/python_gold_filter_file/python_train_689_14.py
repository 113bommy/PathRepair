n , d = map(int , input().split())
l = sorted(list(map(int , input().split())))
def check(t):
    global n , d , l
    if(t == n):
        return True
    if(t == 0):
        return l[-1] - l[0] <= d;
    for i in range(t + 1):
        le = l[i]
        ri = l[n - t + i - 1]
        if(ri - le <= d):return True
    return False
L = -1;
R = n;
while(R - L > 1):
    mid = (L + R) // 2
    if(check(mid)):
        R = mid
    else:
        L = mid
print(R)

