from collections import Counter as c
input()
a=c(map(int,input().split()))
b=0
for i in sorted(a.keys()):
 if not i:
  b+=a[0]*(a[0]-1)//2
  break
 b+=a[i]*a[-i]
print(b)