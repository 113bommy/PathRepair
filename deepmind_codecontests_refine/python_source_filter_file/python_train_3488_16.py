from math import floor
def seal(a, b):
    return (a + b - 1)//b
k,a,b = map(int,input().split())
ans = abs(b)//k + abs(a)//k
if(a < 0 and b >=0):
    values = b - a + 1
    print(ans + 1)
else:
    a,b = abs(a), abs(b)
    a,b = min(a,b), max(a,b)
    lower = seal(a,k)
    upper = floor(b/k)
    print(upper - lower + 1)
    # if(a % k == 0 and b % k == 0 and k != 1):
    #     ans += 1
    # print(ans)