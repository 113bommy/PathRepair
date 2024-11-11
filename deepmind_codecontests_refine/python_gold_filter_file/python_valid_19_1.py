import sys
input = sys.stdin.readline

t=int(input())
for tests in range(t):
    n=int(input())
    A=list(map(int,input().split()))

    if n==1:
        if A[0]==0:
            print("YES")
        else:
            print("NO")
        continue

    if 0 in A:
        print("YES")
        continue

    X=[A[0]]

    for i in range(1,n):
        a=A[i]
        Y=[a]
        for x in X:
            Y.append(x+a)
            Y.append(x-a)
        X+=Y

    if 0 in X:
        print("YES")
    else:
        print("NO")
