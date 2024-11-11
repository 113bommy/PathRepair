n = int(input())
A = list(map(int,input().split()))
d = set(A)
if(len(d)>3):
    print("NO")
else:
    D=list(d)
    D.sort()
    if(len(d)==3):
        if(A[1]-A[0]!=A[2]-A[1]):
            print("NO")
        else:
            print("YES")
    else:
        print("YES")