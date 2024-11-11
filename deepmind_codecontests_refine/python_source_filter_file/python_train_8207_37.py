x = int(input())
c = x // 11
r = x % 11
if(r > 5):
  c += 2
elif(r > 0):
  c += 1
print(c)