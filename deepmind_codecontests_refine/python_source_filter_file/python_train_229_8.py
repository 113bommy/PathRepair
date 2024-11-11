t=int(input())
for tc in range(t):
    n=int(input())
    num=[[0,0]]
    f1=0
    for i in range(n):
        s=input().split()
        p,c=int(s[0]),int(s[1])
        if c>p:
            f1=1
        else:
            pp=num[i][0]
            pc=num[i][1]
            if p>=pp+c and c>=pc:
                pass
            else:
                f1=1
        num.append([p, c])
    if f1==0:
        print("YES")
    else:
        print("NO")