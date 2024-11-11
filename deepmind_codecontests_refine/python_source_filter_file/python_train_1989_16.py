import math
n=int(input())
m=int(input())
lst=[]
for j in range(n):
    i1=int(input())
    lst.append(i1)
M=max(lst)
m2=M+m
s=0
for j in range(n):
    s+=M-lst[j]
if m<=s:
    m1=m
else:
    m1=math.ceil((m-s)/n)+M
print(m1,m2,end=" ")