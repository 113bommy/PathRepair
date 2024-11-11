t=int(input())
while t:
    t-=1
    n=int(input())
    a=list(map(int,input().split()))
    if len(set(a))==1:
        if a[0]==1:
            if n%2==0:
                print("second")
            else:
                print("First")
        else:
            print("First")
    else:
        w=0
        for i in range(n):
            if a[i]==1:
                w+=1
            else:
                w+=1
                break
        if w%2==0:
            print("Second")
        else:
            print("First")
            