A,B,C=map(int,input().split())

if A+B>=C-1:
    print(B+C)
else:
    print(2*A+2*B+1)