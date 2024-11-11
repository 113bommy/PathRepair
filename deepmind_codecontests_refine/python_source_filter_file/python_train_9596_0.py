MOD = 998244353
# Read input
n = int(input())
a = []
b = []

fact = [1]

for i in range(n):
    x_a, x_b = input().strip().split(' ')
    a.append(int(x_a))
    b.append(int(x_b))

for i in range(1, n+1):
    fact.append((fact[i-1] * i) % MOD)

def count_permutations(arr):
    f = dict()
    for x in arr:
        try:
            f[x] += 1
        except:
            f[x] = 1
    res = 1
    for _, v in f.items():
        res *= fact[v]
        res %= MOD
        
    return res

# Count bad sequences with first element
bad_a = count_permutations(a)

# Count bad sequences with second element
bad_b = count_permutations(b)

# Count bad sequences with both elements
bad_common = 0
pairs = [[a[i], b[i]] for i in range(n)]
pairs = sorted(pairs, key = lambda x: (x[0], x[1]))
second = [x[1] for x in pairs]
if second == sorted(second):
    bad_common = count_permutations(second)

res = fact[n] - bad_a - bad_b + bad_common
print(res % MOD)