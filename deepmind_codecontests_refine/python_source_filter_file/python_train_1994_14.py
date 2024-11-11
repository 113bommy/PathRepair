n = int(input())
A = list(map(int,input().split()))
A=set(A)
A=list(A)
A.sort()
if(len(A)==1):
    print("0")
elif(len(A)==2):
    if(A[1]-A[0])%2==0:
        print((A[1]-A[0])//2)
    else:
        print(A[1]-A[0])
elif(len(A)==3):
    if(A[2]-A[1] == A[1]-A[2]):
        print(A[1]-A[0])
    else:
        print("-1")
else:
    print("-1")
    