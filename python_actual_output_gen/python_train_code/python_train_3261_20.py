n=int(input())
a=list(map(int,input().split()))
b=max(a)
c=b
d=0
for i in a:
  if c>abs(b/2-i):c=abs(b/2-i);d=i
print(b,d)