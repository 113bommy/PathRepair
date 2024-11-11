n = int(input())
a = list(map(int,input().split()))
for i in range(1,n):
    a[i] += a[i-1]
c = a[-1]
for i in range(n):
   p = abs(a[-1]-a[i]*2)
      if c > p:
        c = p   
print(c) 