"""
Brandt Smith, Peter Haddad, Lemuel Gorion

Codeforces.com

Problem 165B
"""

def summ(v, k):
    s = 0
    while v:
        s += v
        v = v // k
        
    return s

n, k = map(int, input().split(' '))
left, right, m = 1, n, 0

while True:
    if left >= right:
        break

    m = (left + right) // 2

    if summ(m, k) >= n:
        right = m
    else:
        left = m + 1

print(right)



