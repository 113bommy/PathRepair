N = int(input())
A = list(map(int,input().split()))
B = list(map(int,input().split()))

def search3(w,v,n):
    res = 0
    for n1 in range(n//w[0]+1):
        for n2 in range((n-w[0]*n1)//w[1]+1):
            n3 = (n-w[0]*n1-w[1]*n2)//w[2]
            res = max(res,n+(v[0]-w[0])*n1+(v[1]-w[1])*n2+(v[2]-w[2])*n3)
    return res

def search2(w,v,n):
    res = 0
    for n1 in range(n//w[0]+1):
        n2 = (n-w[0]*n1)//w[1]
        res = max(res,n+(v[0]-w[0])*n1+(v[1]-w[1]*n2))
    return res

AB = [[A[0]-B[0],A[0],B[0]],[A[1]-B[1],A[1],B[1]],[A[2]-B[2],A[2],B[2]]]
AB.sort()
A = [AB[i][1] for i in range(3)]
B = [AB[i][2] for i in range(3)]

if AB[0][0]>0:
    ans = search3(B,A,N)
elif AB[1][0]>0:
    n = N+(B[0]-A[0])*(N//A[0])
    ans = search2(B[1:],A[1:],n)
elif AB[2][0]>0:
    n = search2(A[:2],B[:2],N)
    ans = n+(A[2]-B[2])*(n//B[2])
else:
    ans = search3(A,B,N)

print(ans)