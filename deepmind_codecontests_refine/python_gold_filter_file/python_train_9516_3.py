n=int(input())
Ar=[int(x) for x in input().split()]
A=[]
m=min(Ar)
# print(m)
for i in range(9):
#     print(i)
    if Ar[i]==m:
        A.append(i+1)
#         print(A)
if m<=n:
    k=n//m
    p=list(str(A[-1])*(k))
#     print(p)
    remain=n-(k*Ar[A[-1]-1])
#     print(remain)
#     print(A[-1])
    s=0
    for i in range(9,A[-1],-1):
#         print(Ar[i-1],Ar[A[-1]-1])
        while Ar[i-1]-Ar[A[-1]-1]<=remain:
#             print(remain)
            remain-=(Ar[i-1]-Ar[A[-1]-1])
#             print(remain)
            p[s]=str(i)
            s+=1
    print(''.join(p))
        
else:
    print(-1)