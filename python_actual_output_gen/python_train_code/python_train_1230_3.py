t = int(input())
for  _ in range(t):
    n = int(input())
    a = list( map(int,input().split()))
    b = list( map(int,input().split()))
    pos = -9
    neg = -9
    if b[0]!=a[0]:
        print("NO")
    else:
       
        f = 0

        for i in range(1,n-1):
            if a[i-1] == -1:
                neg = a[i]
            elif a[i-1] == 1:
                pos = a[i]
            if a[i] > b[i] and neg==-9:
                f = -1
                print("NO")
                break
            
            if a[i] < b[i] and pos ==-9:
                f = -1
                print("NO")
                break
        if f==0:
            print("YES")
            