n = int(input())
s = []
for i in range(n):
  s.append(int(input()))
m=sum(s)
s.sort()
for x in s:
  if (m-x)%10!=0:
    print(m-x)
    exit()
print(0)
