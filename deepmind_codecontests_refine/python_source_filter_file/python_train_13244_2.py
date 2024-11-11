test=int(input())

s=[]


for i in range(test):
    n,d=list(map(int,input().split(" ")))
    s=list(map(int,input().split(" ")))
    ans = 9999999999999
    for j in s:
        if d%j==0:
            h=d/j
            if ans>h:
                ans=d/j
        elif j>d:
            if ans>2:
                ans=2
        else:
            h = (d/j)+1
            if ans>h:
                ans = int(h)
    print(ans)


