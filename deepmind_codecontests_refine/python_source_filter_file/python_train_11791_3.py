def solve():
    n=int(input())
    s="codeforces"
    l=[1]*10
    t=1
    i=0
    while t<n:
        t=t//l[i]
        l[i]=l[i]+1
        t=t*l[i]
        i=(i+1)%10
    print(l)
    for i in range(10):
        print(s[i]*l[i],end="")
        
if __name__=="__main__":
    solve()
