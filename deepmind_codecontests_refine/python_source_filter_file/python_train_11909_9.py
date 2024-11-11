n=int(input())
if n<3 or (n-1)%2!=0:
    print(-1)
else:
    A=[int(i) for i in range(n)]
    B=[n-1]
    B+=[int(i) for i in range(n-1)]
    C=[]
    for i in range(n):
        C.append((A[i]+B[i])%n)
    print(*A)
    print(*B)
    print(*C)