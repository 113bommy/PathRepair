n=int(input())
dic = {}
a = 0
for i in range(n):
  s = ''.join(sorted(input()))
  if s in dic:
    a += dic[s]
    dic[s] += 1
  else:
    dic[s] = 1
print(a)