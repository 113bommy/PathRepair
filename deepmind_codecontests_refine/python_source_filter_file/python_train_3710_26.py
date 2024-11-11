from math import ceil

[h1,a1,c1] = input().split(' ')
[h2,a2] = input().split(' ')

h1 = int(h1)
a1 = int(a1)
c1 = int(c1)
h2 = int(h2)
a2 = int(a2)

t = 0
s = []

while h2>0:
    if a1>h2:
        t+=1
        s.append('STRIKE')
        h2=0
    elif h1<=a2:
        h1= h1+c1-a2
        t+=1
        s.append('HEAL')
    else:
        h1 = h1 - a2
        h2 = h2 -a1
        t+=1
        s.append('STRIKE')

print(t)
for i in s:
    print(i)
    
