def solve(n,k):
    return n+(k-1)*9
t=1
t=int(input())
while(t>0):
    n,k=[int(x) for x in input().split()]
    print(solve(n,k))
    t-=1