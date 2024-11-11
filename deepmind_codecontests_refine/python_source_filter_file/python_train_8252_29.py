t=int(input())
def solve():
    n=int(input())
    print(n)
    a=n
    while(a>0):
        print(a,end=" ")
        a-=1
while(t>0):
    solve()
    print("")
    t-=1