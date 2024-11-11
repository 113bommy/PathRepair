n = int(input())

l = [0]*(n+1)
for i in range(2, n+1):
  cur = i
  for j in range(2, i+1):
    while cur % j == 0:
      cur //= j
      l[j] == 1

def num(s):
  return len(list(filter(lambda x: x >= s-1, l)))

print(num(75)+num(25)*(num(3)-1)+num(15)*(num(5)-1)+num(5)*(num(5)-1)*(num(3)-2)//2)
