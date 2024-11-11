t=int(input())
def fun(n,a):
    p=a[0][0]
    c=a[0][1]
    if c<=p:
        flag=0
        for i in range(1,n):
            if p<=a[i][0] and c<=a[i][1] and a[i][0]>=a[i][1]:
                p=a[i][0]
                c=a[i][1]

            else:
                flag+=1
                break
        if flag:
            print("NO")
        else:
            print("YES")
    else:
        print("NO")
while t:
    t-=1
    n=int(input())
    a=[]
    for i in range(n):
        p,q=map(int,input().split())
        a.append((p,q))
    fun(n,a)

