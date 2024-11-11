for t in range(int(input())):
    n=int(input())
    l=list(map(int,input().split()))
    l.sort()
    flag=0
    for j in range(n-1,0,-1):
        if l[j]<=j+1:
            flag=1
            print(j+2)
            break
    if flag==0:
        print(1)