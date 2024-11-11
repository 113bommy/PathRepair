from sys import stdin, stdout

mod = 998244353

def pow_mod(x, y):
    if y == 1:
        return x % mod 

    half_res = pow_mod(x, y // 2)
    result = half_res * half_res
    if y % 2 == 1:
        result *= x

    return result % mod 

t = int(stdin.readline())
for tt in range(t):
    n = int(stdin.readline())
    a = [int(s) for s in stdin.readline().split()]

    ones = 0
    mx = 0
    for i in range(n):
        if a[i] == 1:
            ones += 1
        if a[i] > mx:
            mx = a[i]

    sm = pow_mod(2, ones) - 1 if ones > 0 else 0

    # print(sm, '~~~')

    ending_to = [0 for i in range(mx + 1)]
    done_to = [0 for i in range(mx + 1)]

    for i in range(n):
        ending_to[a[i]] *= 2
        if a[i] != 0:
            ending_to[a[i]] += ending_to[a[i] - 1]
        else:
            ending_to[a[i]] += 1
        ending_to[a[i]] %= mod

        if a[i] >= 2:
            done_to[a[i] - 1] *= 2
            done_to[a[i] - 1] += ending_to[a[i] - 2]
            done_to[a[i] - 1] %= mod

        if a[i] <= mx - 1 and done_to[a[i] + 1] > 0:
            done_to[a[i] + 1] *= 2
            done_to[a[i] + 1] += ending_to[a[i] - 1] if a[i] > 0 else 0
            done_to[a[i] + 1] %= mod

    # for i in range(mx + 1):
    #     print(i, ending_to[i], '!')
    #     print(i, done_to[i], '!!')

    for i in range(mx + 1):
        sm = (sm + ending_to[i] + done_to[i]) % mod

    sm %= mod

    stdout.write(str(sm) + '\n')