a,b = input().split(":")
min = 0
a_rev = a[::-1]
while(int(a_rev)<int(b) or int(a_rev)>=60):
  min+=(60-int(b))
  b = 0
  a = '{0:02}'.format((int(a)+1)%24)
  a_rev = a[::-1]
  print(a,b,a_rev,min)
min+=int(int(a_rev)-int(b))
print(min)