def even(a):
    return a%2==0
def solve(n,m,k):
    if k==-1:
        if int(even(n))+int(even(m))==1:
            print(-1)
            return
    print(pow(2,(n-1)*(m-1),1000000007))
solve(*[int(i) for i in input().split()])
