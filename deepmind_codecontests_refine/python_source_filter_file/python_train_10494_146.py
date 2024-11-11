N,A,B,C,D=map(int,input().split())
S=input()
A-=1
B-=1
C-=1
D-=1
if "##" in S[A:C+1] or "##" in S[B:D+1]:
    print('No')
else:
    if C<D:
        print('Yes')
    else:
        if "..." in S[B:D+1]:
            print('Yes')
        else:
            print('No')