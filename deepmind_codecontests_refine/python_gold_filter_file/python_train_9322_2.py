n = int(input())
x = list(map(int,input().split(' ')))
q = int(input())
m = [0]*q
for i in range(0,q):
    m[i]=int(input())

x.sort()
d = [0]*(x[-1])
for i in x:
    d[i-1] = d[i-1]+1
a = [0]*len(d)
a[0] = d[0]
for i in range(1,len(d)):
    a[i] = a[i-1]+d[i]
for i in m:
    if i>len(d):
        print(len(x))
    else:
        print(a[i-1])
