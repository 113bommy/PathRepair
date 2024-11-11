def find(N,M):
    for i in range(N):
        A=['B']*M
        if i==0: A[0]='W'
        print(' '.join(A))
def main():
    for i in range(int(input())):
        N,M=list(map(int,input().split()))
        find(N,M)


main()