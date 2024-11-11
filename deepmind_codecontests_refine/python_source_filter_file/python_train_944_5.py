n = int(input())
k = ['L','M','S','XS','XL','XXS','XXL','XXXS','XXXL']

d = {'L':0,'M':0,'S':0,'XS':0,'XL':0,'XXS':0,'XXL':0,'XXXS':0,'XXXL':0}

for i in range(n):
    s = input()
    d[s] = d[s]+1

q = {'L':0,'M':0,'S':0,'XS':0,'XL':0,'XXS':0,'XXL':0,'XXXS':0,'XXXL':0}

for i in range(n):
    s = input()
    q[s] = q[s] +1

for s in k:
    p = min(d[s],q[s])
    d[s]-= p
    q[s]-= p

c = 0
for s in k:
    if d[s]!=0:
        c+=1
print(c)

