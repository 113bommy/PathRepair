n = int(input())
a = []
res = 1

def f(b, e):
  global res
  if b+1 >= e:
    return
  if sorted(a[b:e]) == a[b:e]:
    res = max(res, e-b)
  f(b, (b+e)//2)
  f((b+e)//2, e)

a = list(map(int, input().split()))

f(0, n)
print(res)