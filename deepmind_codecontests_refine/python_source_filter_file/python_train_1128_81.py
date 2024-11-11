n = int(input())
a = list(map(int,input().split()))

b=0
for i in range(n):
  if a[i]//400>=8:
    b+=1
c=[s//400 for s in a if s<3200]
C=len(set(c))
print(C, C+b)