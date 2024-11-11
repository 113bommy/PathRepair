for _ in range(int(input())):
    n = int(input())
    p = []*n
    for _ in range(n):
        a,b=map(int,input().split())
        p.append((a,b))
    p.sort()
    ans=[]
    f=0
    ans.extend(('R')*(p[0][0]))
    ans.extend(('U')*(p[0][1]))
    for i in range(1,n):
        x=p[i][0]-p[i-1][0]
        y=p[i][1]-p[i-1][1]
        if x>=0 and y>=0:
            ans.extend(('R')*x)
            ans.extend(('U')*y)
        else:
            f=1
            break;
    if f==0:
        print("YES")
        ans1=''.join(map(str,ans))
        print(ans1,end='')
    else:
        print("NO")