h,w = map(int, input().split())
a = [(_ for _ in input()) for i in range(h)]
b = [x for x in a if '#' in x]
c = zip(*[y for y in zip(*b) if '#' in y])

for d in c:
  print(''.join(d))