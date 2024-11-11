I=input
n,m=map(int,I().split())
l=set([1,n])
t=set([1,n])
for i in range(m):
    a,b=map(int,I().split())
    l.add(a)
    t.add(b)
total=n-len(t)+n-len(l)
m=int(n/2)
if n%2 and (m not in l) and (m not in t): total-=1
print(total)