N, M = map(int, input().split())

a = set(str(x) for x in range(1,M+1))
for i in range(N):
  li = list(input().split())
  a = a & set(li[1:])

print (len(a))