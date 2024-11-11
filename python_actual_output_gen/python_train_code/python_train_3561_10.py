n = input()
a = [int(i) for i in input().split()]
c = -a[0]
d = 0
for i in range(len(a)-1):
  rem = a[i] - a[i+1]
  c+=rem
  if(c<d):
    d = c
print(abs(d))
