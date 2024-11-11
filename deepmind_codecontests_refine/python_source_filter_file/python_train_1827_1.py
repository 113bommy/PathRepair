def get_ints():
    return list(map(int, input().split()))

N,M = get_ints()
for i in range(1,2*N+1):
    if 2*N+i<=M:
        print(2*N+i, end=" ")
    print(i,end=" ")