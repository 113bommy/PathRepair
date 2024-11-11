n = int(input())
a = list(map(int,input().split()))
s = sum(a)
a.sort()
b = 1
for i in a:
  b |= b<<i
  
b &= 2**(s+1)-2**((s-1)//2)
t = b&(-b)
print(t.bit_length()-1)