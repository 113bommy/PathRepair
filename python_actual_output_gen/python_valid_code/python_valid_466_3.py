for _ in range(int(input())):
    n=int(input())
    a=list(map(int,input().split()))
    s=input()
    b=[]
    for i,j in zip(a,s):
        b.append([i,j])
    b.sort()
    f=1
    for i in range(n):
        if(b[i][1]=='R' and b[i][0]>(i+1)):
            f=0
            break
        elif(b[i][1]=='B' and b[i][0]<(i+1)):
            f=0
            break
    if(f):
        print('YES')
    else:
        print("NO")