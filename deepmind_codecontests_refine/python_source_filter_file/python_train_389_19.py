from math import gcd

n = int(input())
a = list(map(int, input().split()))

checker = [0 for _i in range(10**6+1)]
for i in a:
    checker[i] += 1

if any(sum(checker[i::i])>1 for i in range(2, 10**6+1)):
    print('pairwise coprime')
else:
    r = a[0]
    for i in a:
        r = gcd(r, i)
    if r == 1:
        print('setwise coprime')
    else:
        print('not coprime')