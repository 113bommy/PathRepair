c = 0
for i in range(int(input())):
  if (i%3!=0)&(i%5!=0):
    c += i
print(c)