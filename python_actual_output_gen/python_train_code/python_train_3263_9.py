n=int(input())
l=sorted([int(input()) for _ in range(n)])
s=sum(l)
for i in l[::-1]:
  if i%10>0:k=s-i
print(s if s%10>0 else k)