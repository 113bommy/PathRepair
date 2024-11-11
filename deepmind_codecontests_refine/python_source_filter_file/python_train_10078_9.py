N=int(input())
A=[int(x) for x in input().split()]
B=[x for x in A if x<0]
absA=[abs(x) for x in A]
if len(B)%2==0:
  minus=0
else:
  minus=max(B)
  
print(sum(absA)+minus)