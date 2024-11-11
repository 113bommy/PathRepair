from operator import itemgetter

N = int(input())
A = list(map(int, input().split()))

i = max(enumerate(map(abs, A)), key=itemgetter(1))[0]
print(2*N)
if A[i]<0:
    print(i+1, N)
    print(i+1, N)
    for j in range(N, 1, -1) :
        print(j, j-1)
        print(j, j-1)
else :
    print(i, 0)
    print(i, 0)
    for j in range(1, N) :
        print(j, j+1)
        print(j, j+1)