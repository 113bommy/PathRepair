h,w = map(int,input().split())
a = [[j for j in input()] for i in range(h)]
b = [x for x in a if "#" in x]
print(*b)
c = zip(*[y for y in zip(*b) if "#" in y])
#print(list(c))
for d in c:
  print("".join(d))