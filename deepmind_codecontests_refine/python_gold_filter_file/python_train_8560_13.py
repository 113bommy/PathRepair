from math import floor
def solve(x,n,m):
    if m*10>=x:
        flag = True
    else:
        flag = False
        for i in range(n):
            x = floor(x/2)+10
        for i in range(m):
            x=x-10
            if x<=0:
                flag=True
                break
    if flag == True:
        print("YES")
    else:
        print("NO")
    
for i in range(int(input())):
    x,n,m = map(int,input().split())
    #a = list(map(int,input().split()))
    solve(x,n,m)