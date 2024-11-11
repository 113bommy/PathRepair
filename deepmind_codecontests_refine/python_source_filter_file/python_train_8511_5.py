from math import gcd

def euclid(A,B):
    if B==1:
        return 1,1-A
    else:
        q,r = A//B,A%B
        x1,y1 = euclid(B,r)
        return y1,x1-q*y1

N = int(input())
ans = 2*N
for i in range(1,2*N+1):
    if i**2>(2*N):
        break
    if N%i:
        continue

    A,B = i,(2*N)//i

    if gcd(A,B)!=1:
        continue

    x0,y0 = euclid(A,B)

    limit1 = (1-y0)//A
    if limit1*A+y0<1:
        limit1+=1

    limit2 = (x0+1)//B
    if limit2*B- x0<1:
        limit2+=1

    limit = max(limit1,limit2)

    tmp = (B*limit-x0)*A
    ans = min(ans,tmp)

    A,B = (2*N)//i,i

    x0,y0 = euclid(A,B)

    limit1 = (1-y0)//A
    if limit1*A+y0<1:
        limit1+=1

    limit2 = (x0+1)//B
    if limit2*B- x0<1:
        limit2+=1

    limit = max(limit1,limit2)

    tmp = (B*limit-x0)*A
    ans = min(ans,tmp)

print(ans)