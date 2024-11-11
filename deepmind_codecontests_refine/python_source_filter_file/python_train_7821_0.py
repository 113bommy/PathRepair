n=input()
b=input()
a=[int(i) for i in b.split()]
n=int(n)
t=0
q=10000000007
for i in range(n):
    t=t+min(q,a[n-1-i])
    q=min(q,a[n-1-i]-1)
print(t)
