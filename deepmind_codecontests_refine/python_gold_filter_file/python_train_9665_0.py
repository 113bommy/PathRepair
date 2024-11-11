N = int(input())
a = set()
for i in range(N):
  a ^= {input()}
print (len(a))