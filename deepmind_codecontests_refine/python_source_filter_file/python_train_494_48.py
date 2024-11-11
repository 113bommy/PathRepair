import sys
import math
mod = 1000000007

n = int(sys.stdin.readline().rstrip())
ab = {}
for i in range(n):
    a,b = map(int,sys.stdin.readline().rstrip().split())
    if a == 0 and b == 0:
        pass
    elif a == 0:
        b = 1
    else:
        gcd = math.gcd(a,b)
        a //= gcd
        b //= gcd
        if a < 0:
            a = -a
            b = -b
    ab.setdefault((a,b),0)
    ab[(a,b)]+=1
ans = 0
pairs=[]
s = list(set(ab.keys()))
for i in ab.keys():
    a = i[0];b = i[1]
    if a == 0 and b == 0:
        ans = ab[(0,0)]
        n -= ans
    else:
        if (-b, a) in s:
            pairs.append([ab[(a,b)],ab[(-b,a)]])
select = 1
for pair in pairs:
    select*= (pow(2,pair[0],mod) + pow(2,pair[1],mod) -1)
    n -= (pair[0]+pair[1])
all_ans = (pow(2,n,mod) * select) % mod + ans -1
all_ans %= mod
print(all_ans)