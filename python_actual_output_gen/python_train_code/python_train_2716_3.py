for tc in [0]*int(input()):
    n=int(input())
    l=list(map(int,input().split()))
    f=0
    for i in range(n//2):
        if l[i]+1 in l or l[i]-1 in l:
            f=1
            print(2)
            break
    if f==0:
        print(1)