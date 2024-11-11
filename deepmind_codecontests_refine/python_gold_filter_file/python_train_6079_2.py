def solve():
    l=list(input())
    n=len(l)
    r=[0 for i in range(n)]
    for i in range(1,n):
        r[i]=r[i-1]+(l[i]==l[i-1])
    #print(r)
    for i in range(int(input())):
        ro,c=map(int,input().strip().split())
        print(r[c-1]-r[ro-1])
if __name__=="__main__":
    solve()
