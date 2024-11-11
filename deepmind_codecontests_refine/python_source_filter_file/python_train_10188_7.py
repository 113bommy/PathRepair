n = int(input())
p = reversed(list(map(int, input().split())))
a = [i*20000 for i in range(1,n+1)]
b = [i*20000 for i in range(n,0,-1)]
for k,v in enumerate(p):
  b[v-1] -= k
print(a)
print(b)
