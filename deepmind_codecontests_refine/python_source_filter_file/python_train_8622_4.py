q = int(input())
p = [False]*(10**5)
c = [0]*(10**5)
temp = [True]*(N+1)
temp[0] = False
temp[1] = False
for i in range(2, 10**5):
  c[i] = c[i-1]
  if temp[i]:
    temp[2*i::i] = [False]*(len(temp[i+i::i]))
    if temp[(i+1)//2] and i%2:
      c[i] += 1

for _ in range(q):
  l, r = map(int, input().split())
  print(c[r] - c[l-1])