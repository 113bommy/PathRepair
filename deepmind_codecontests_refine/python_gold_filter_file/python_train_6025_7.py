N,L = map(int,input().split())
A = list(map(int,input().split()))

B = [A[i-1] + A[i] for i in range(1,N)]

if max(B) < L :
    print("Impossible")
else :
    print("Possible")

    ind = B.index(max(B))
    for i in range(ind) :
        print(i+1)
    for i in range(N-1,ind,-1) :
        print(i)
