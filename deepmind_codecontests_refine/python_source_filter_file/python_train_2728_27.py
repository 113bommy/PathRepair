t = int(input())
v1,v2=0,0
for i in range(t):
    n=int(input())
    flag="NO"
    a=list(map(int,input().split()))
    for j in range(len(a)-1):
        if abs(a[j+1]-a[j])>=2:
            flag="YES"
            v1=j
            v2=j+1
            break
    if flag=="NO":
        print("NO")
    else:
        print("YES")
        print(v1,v2,end=" ")
    print("")