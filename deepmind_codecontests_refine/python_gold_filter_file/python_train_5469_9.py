def gcd(a,b):
  if b == 0:
    return a
  else:
    return gcd(b, a%b)
  
n = int(input())
a = list(map(int, input().split()))
b = []
b.append(a[0])
s = 0
for i in range(1, len(a)):
  if gcd(a[i], a[i-1]) != 1:
    b.append(1)
    s+=1
  b.append(a[i])
print(s)
print(*b)