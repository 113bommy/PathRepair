n, k = map(int, input().split())
a = list(map(int, input().split()))
a.sort()


def f(m, k, n, a):
   j = n // 2
   g = a[j]
   if m - g > 0:
      k -= m - g
   for i in range(j + 1, n):
      if a[i] <= m:
         k -= m - a[i]
   return k >= 0 
   
   
    
    
l = a[0]
r = a[-1] + k
    
while r - l > 1:
   m = (l + r) // 2
   if f(m, k, n, a):
      l = m
   else:
      r = m
      
print(l)