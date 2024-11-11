n = int(input())

a = list(map(int, input().split()))

a.sort()

b = -(a[0]-a[n-1])
c = -(a[n]-a[2*n - 1])

m = b*c

x = a[-1]-a[0]

for i in range(1,n) :
    m = min(m,x*(a[-i]-a[i]))

print(b*c)
