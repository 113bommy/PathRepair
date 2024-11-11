#diverta 2019 Programming Contest 2 -C Successive Subtraction
import sys
readline = sys.stdin.buffer.readline
def even(n): return 1 if n%2==0 else 0
n = int(readline())
lst1 = list(map(int,readline().split()))

lst1.sort()
lst2 = []
l,r = lst1[0],lst1[-1]
for i in range(1,n-1):
    mid = lst1[i]
    if mid < 0:
        lst2.append([r,mid])
        r -= mid
    else:
        lst2.append([l,mid])
        l -= mid
lst2.append([l,r])
print(r-l)
for i in lst2:
    print(*i)