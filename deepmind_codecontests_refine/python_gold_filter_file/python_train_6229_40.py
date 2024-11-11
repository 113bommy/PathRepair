a, b = map(int, input().split())
L = [["#"]*100 for _ in range(50)] + [["."]*100 for _ in range(50)]
qa, ra = divmod(a-1, 50)
for i in range(qa):
  L[i*2] = ["#" if j%2 else "." for j in range(100)]
L[qa*2] = ["#" if j%2 else "." for j in range(ra*2)] + ["#"]*(100-ra*2)
qb, rb = divmod(b-1, 50)
for i in range(qb):
  L[51+i*2] = ["." if j%2 else "#" for j in range(100)]
L[51+qb*2] = ["." if j%2 else "#" for j in range(rb*2)] + ["."]*(100-rb*2)
print(100, 100)
for l in L:
  print(*l, sep="")