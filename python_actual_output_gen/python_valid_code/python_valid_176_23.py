# https://codeforces.com/problemset/problem/450/B

"""
f_1 = x, f_2 = y
f_{i+1} = f_i - f_{i-1}

Calculate f_n modulo 10**9 + 7
"""

x, y = map(int, input().split())
n = int(input()) % 6  # Can show that sequence repeats every 6
f = [x, y, y-x, -x, -y, x-y]

print(f[n] % (10 ** 9 + 7))
