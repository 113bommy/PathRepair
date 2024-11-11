n=int(input())
l=list(input())
q=int(input())
bit=[[0]*(n+1) for i in range(26)]
def bit_sum(o,i):
  s=0
  while i:
    s+=bit[o][i]
    i-=i&-i
  return s
def bit_add(o,i,x):
  while i<=n:
    bit[o][i] += x
    i+=i&-i
for i in range(n):
  bit_add(ord(l[i])-97,i+1,1)
for i in range(q):
  a,b,c=input().split()
  b=int(b)-1
  if a=='1':
    bit_add(ord(l[b])-97,b+1,-1)
    l[b]=c
    bit_add(ord(c)-97,b+1,1)
  else:
    c=int(c)
    print(sum(1 for o in range(26) if bit_sum(o,c)-bit_sum(o,b)))