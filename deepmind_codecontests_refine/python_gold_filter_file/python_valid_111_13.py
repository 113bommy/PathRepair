T = int(input())
while T>0:
    T-=1
    n = int(input())
    x = "()"
    i=n-1
    ans = []
    ans.append(x*n)
    while i>0:
        ans.append(x*(n-i-1)+"(())"+x*(i-1))
        i-=1
    for i in ans:
        print(i)