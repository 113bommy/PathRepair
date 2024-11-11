for i in range(int(input())):
    n=int(input())
    l=[]
    for j in range(n):
        l.append(input())
    log=0
    for x in range(n):
        for y in range(n):
            if int(l[x][y])==1:
                if not ((x+1)==n and (y+1)==n and int(l[x+1][y])==1 and int(l[x][y+1])==1):
                    log=1
                    break
        if log==1:
            break
    if log==1:
        print("NO")
    else:
        print("YES")
                    