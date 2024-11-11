"""
Codeforces Round 257 Div 1 Problem A

Author  : chaotic_iak
Language: Python 3.3.4
"""

def read(mode=2):
    # 0: String
    # 1: List of strings
    # 2: List of integers
    inputs = input().strip()
    if mode == 0:
        return inputs
    if mode == 1:
        return inputs.split()
    if mode == 2:
        return [int(x) for x in inputs.split()]

def write(s="\n"):
    if isinstance(s, list): s = " ".join(map(str,s))
    s = str(s)
    print(s, end="")

################################################### SOLUTION
n,m,k = read()

if n+m-2 < k:
    print(-1)
else:
    mx = 0
    if n > k:
        mx = max(mx, (n//(k+1)) * m)
    else:
        mx = max(mx, 1 * (m // (k-n+1)))
    if m > k:
        mx = max(mx, (m//(k+1)) * n)
    else:
        mx = max(mx, 1 * (n // (k-m+1)))
    print(mx)