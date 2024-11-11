import math
s=input('')
s=s.split(' ')
s=[int(i) for i in s]
n=s[0]
m=s[1]
a=s[2]
z=int(math.ceil(n/a))
w=int(math.ceil(m/a))
q=(w*2+z*2)-4
print(q)