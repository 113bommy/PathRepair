import itertools
from functools import reduce

mod = 10**9+1
n, m = list(map(int, input().split()))

print(pow((pow(2,m,mod)-1)%mod, n, mod))