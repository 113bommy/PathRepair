for u in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    x,y=0,0
    for i in range(n-1):
        if(l[i]!=l[i+1]-1):
            x=x+1
        if(l[i]!=l[i+1]+1):
            y=y+1
    if(x>1 and y>1):
        print("NO")
    else:
        print("YES")
