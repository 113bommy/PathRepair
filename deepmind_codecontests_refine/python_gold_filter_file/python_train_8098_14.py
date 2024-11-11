n = int(input())
m = 0
for i in range(1,n+1):
  if (len(str(i))-1)%2 == 0:
    m += 1
print(m)