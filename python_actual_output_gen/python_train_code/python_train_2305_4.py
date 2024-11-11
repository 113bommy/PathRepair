n = int(input())
a = list(map(int, input().split()))

s = sum(a)

if s%(n*(n+1)//2)!=0:
    print('NO')
    exit()

ss = s//(n*(n+1)//2)

b = [0 for i in range(n)]

# a[i]-a[i-1] = ss-b[i-1]*n
for i in range(n):
    b[i-1] = (ss-a[i]+a[i-1])//n
    if b[i-1]<0:
        print('NO')
        exit()

c = [0 for i in range(n)]
for i in range(n):
    c[0]+=b[i]*(n-i)

for i in range(1,n):
    c[i] = c[i-1] + ss - b[i-1]*n

if a==c:
    print('YES')
else:
    print('NO')

print(b)
