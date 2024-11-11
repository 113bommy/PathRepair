n = int(input())
A = list(map(int,input().split()))
d = set(A)
if(len(d)>3):
    print("NO")
else:
    D=list(d);D.sort()
    if(len(d)==3):
        if(D[1]-D[0]!=D[2]-D[1]):
            print("NO")
        else:
            print("YES")
    else:
        print("YES")