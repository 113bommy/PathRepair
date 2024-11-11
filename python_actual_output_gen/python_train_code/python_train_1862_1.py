n=int(input())
a=input().split()
for i in range(n):
    a[i]=int(a[i])
k=0
g=1
def gcd(c,d):
    if c%d==0:
        return d
    else:
        return gcd(d,c%d)

while True:
    for i in range(n):
        g=gcd(g,a[i])
    if g>1:
        k=0
        break
    else:
        for i in range(n-1):
            if a[i]%2!=0 and a[i+1]%2!=0:
                k+=1
                a[i]=a[i+1]=2
            else:
                pass
        for i in range(n):
            if a[i]%2!=0:
                k+=2
                a[i]=2
        break

print('YES')
print(k)