N,A,B,C,D=map(int, input().split())
S=input()
if S.find("##", A, B)<0 and S.find("##", C, D)<0:
    if C<D:
        print("Yes")
    else:
        if S.find("...", B-1, D+2)>=0:
            print("Yes")
        else:
            print("No")
else:
    print("No")