(n, p, l, r) = map(int, input().split())
if l == 1 and r == n:
   a = 0
   print(1)
elif l == 1:
   a = abs(r - p) + 1
   print(2)
elif r == n:
   a = abs(p - l) + 1
   print(3)
elif p <= l:
   a = (r - p) + 2
   print(4)
elif p > l and p < r and p - l <= r - p:
   a = (p - l) + 2 + (r - l)
   print(5)
elif p > l and p < r and p - l > r - p:
   a = (r - p) + 2 + (r - l)
   print(6)
else:
   a = p - l + 2
   print(7)
print(a)
      
   
   
