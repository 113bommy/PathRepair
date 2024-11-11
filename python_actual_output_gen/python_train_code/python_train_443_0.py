import math
n=int(input())
s=set()
s.add(1)
s.add(n*(n+1)//2)
i=2
while i*i<=n:
    if n % i == 0:
        mo = n // i
        total = mo
        t = mo * (mo - 1) // 2
        t = t * i;
        total += t
        s.add(total)
        mo1= i
        total1 = mo1
        t1 = mo1 * (mo1 - 1) // 2
        t1 = t1* n//i;
        total1 += t
        s.add(total1)
    i+=1
li=list(s)
li.sort()
for i in li:
    print(i,end=' ')

