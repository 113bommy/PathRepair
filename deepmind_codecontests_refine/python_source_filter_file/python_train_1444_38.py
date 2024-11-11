rom math import floor,ceil
def f(b,n):
    if n < b:
        return n
    else:
        return f(b,floor(n/b))+n%b
n = int(input())
s = int(input())

for b in range(2,320000):
    if f(b,n)==s:
        print(b)
        exit()

if n==s:
    print(s+1)
    exit()

d = {}
for i in range(1,ceil(n**0.5)):
    m = f(n//i,n)
    if n//i==n//(i+1):
        d[i] = (m,m)
    else:
        M = f(n//(i+1)+1,n)
        d[i] = (m,M)

for i in range(ceil(n**0.5)-1,0,-1):
    m,M = d[i]
    if m<=s<=M and (s-m)%i==0:
        print(n//i-(s-m)//i)
        exit()

print(-1)