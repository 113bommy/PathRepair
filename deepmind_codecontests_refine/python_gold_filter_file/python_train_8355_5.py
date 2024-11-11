from sys import stdin,stdout
input=stdin.readline
for _ in range(int(input())):
    n,x,y=map(int,input().split())
    p=y-x-1
    r=1
    for i in range(n-1):
        if p-i>=0 and (p-i)%(i+1)==0:
            r=(p-i)//(i+1)
            r+=1
    ans=[x,y]
    for i in range(x+r,y,r):
        if len(ans)==n:
            break
        ans.append(i)
    for i in range(x-r,0,-r):
        if len(ans)==n:
            break
        ans.append(i)
    for i in range(y+r,1000000,r):
        if len(ans)==n:
            break
        ans.append(i)
    print(*ans)