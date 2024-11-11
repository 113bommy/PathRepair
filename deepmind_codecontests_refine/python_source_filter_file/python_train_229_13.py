import sys 
t=int(sys.stdin.readline())
for _ in range(t):
    n=int(sys.stdin.readline())
    a=[]
    for i in range(n):
        p,c=map(int,sys.stdin.readline().split())
        a.append([p,c])
    if a[0][0]<a[0][1]:
        print("NO")
    else:
        flag=True
        for i in range(1,n):
            if a[i][0]<a[i][1] or a[i][1]<a[i-1][1] or a[i][0]<a[i-1][0] or a[i][1]-a[i-1][1]>= a[i][0]<a[i-1][0]:
                flag=False
                print("NO")
                break
        if flag:
            print("YES")
            
    
    