import collections
from decimal import Decimal

n = int(input())
a = [Decimal(input()) for _ in range(n)]
a = [i*10**9 for i in a]
MAX = 19
p_dict = collections.defaultdict(int)

for i in a:
    b_cnt = 0
    while i % 2 == 0 and b_cnt < 18:
        i //= 2
        b_cnt += 1
    f_cnt = 0
    while i % 5 == 0 and f_cnt < 18:
        i //= 5
        f_cnt += 1
    p_dict[(b_cnt, f_cnt)] += 1

ans = 0
for b1, f1 in p_dict:
    for b2, f2 in p_dict:
        if b1+b2 >= 18 and f1+f2 >= 18:
            if b1 == b2 and f1 == f2:
                ans += p_dict[(b1, f1)] * (p_dict[(b2, f2)] - 1)
            else:
                ans += p_dict[(b1, f1)] * p_dict[(b2, f2)]
print(ans//2)