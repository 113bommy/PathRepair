from itertools import permutations

nums = list(map(int, input().split()))
o = input().split()

def f(op, a, b):
  return a * b if op == "*" else a + b

res = 1000 * 4
for a, b, c, d in permutations(nums):
  res = min(res, min(f(o[2], f(o[1], f(o[0], a, b), c), d), \
                     f(o[2], f(o[0], a, b), f(o[1], c, d))))
print(res)