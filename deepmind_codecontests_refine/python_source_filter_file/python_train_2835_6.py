t=int(input())
for i in range(0,t):
    n=input()
    l=[int(i) for i in input().split()]
    rem=l[0]%2
    temp=0
    for e in l[1:]:
        if(e%2!=temp):
            temp=1
            break
    if(temp==0):print("YES")
    else:print("NO")