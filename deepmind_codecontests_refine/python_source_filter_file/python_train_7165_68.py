N = int(input())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

c = 0
for i in range(N):
   if b[i] - a[i] > 0:
      c += b[i] - a[i]
   elif b[i] - a[i] < 0:
      c += (b[i] - a[i])*2

if c >= 0:
   print("Yes")
else:
   print("No")
