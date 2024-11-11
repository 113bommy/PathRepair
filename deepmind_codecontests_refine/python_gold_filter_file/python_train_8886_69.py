q = int(input())
a = input()
b = list(a)
n0 = b.count('R')
m0 = b.count('G')
p0 = b.count('B')
t = 0
while 'RR' in a:
    a=a.replace('RR','R')
b1 = list(a)
n1 = b1.count('R')
while 'GG' in a:
    a=a.replace('GG','G')
b2 = list(a)
m1 = b2.count('G')
while 'BB' in a:
    a=a.replace('BB','B')
b3 = list(a)
p1 = b3.count('B')
t = n0 + m0 +p0 -n1 -m1 -p1

print(t)
    
