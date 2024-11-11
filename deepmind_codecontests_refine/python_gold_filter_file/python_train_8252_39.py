t=int(input())
def solve():
    n=int(input())
    print(n)
    a=1
    while(a<=n):
        print(a,end=" ")
        a+=1
while(t>0):
    solve()
    print("")
    t-=1