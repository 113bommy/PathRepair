import bisect

N=int(input())
A=[int(i) for i in input().split(" ")]
A=sorted(A)
traceback=[]

if A[0]>=0:
    minus=[A[0]]
    plus=A[1::]
elif A[-1]<=0:
    minus=A[:-1:]
    plus=[A[-1]]
else:
    index=bisect.bisect_left(A,0)
    minus=A[:index:]
    plus=A[index::]

print(sum(plus)-sum(minus))
m=minus.pop(0)
for p in plus[:-1:]:
    print(m,p)
    m=m-p
print(plus[-1],m)
p=plus[-1]-m
for m in minus:
    print(p,m)
    p=p-m
