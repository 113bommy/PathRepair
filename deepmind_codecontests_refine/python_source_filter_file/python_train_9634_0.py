from itertools import permutations

base = 7
digits = [x for x in range(base)] 

def get_count(n):
    answer = 1
    while (n > base):
        n = n // base
        answer += 1
    return answer

def is_good(tup, n):
    a = 0
    for x in reversed(tup):
        a *= base
        a += x
    if a >= n:
        return False
    else:
        return True

n, m = map(int, input().split())

h_count = get_count(n)
m_count = get_count(m)

answer = 0

for perm in permutations(digits, h_count + m_count):
    if is_good(perm[:h_count], n) and is_good(perm[h_count:], m):
        answer += 1

print(answer)


