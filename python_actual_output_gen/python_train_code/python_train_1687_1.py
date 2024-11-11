n=int(input())
for i in range(n):
    a=list(map(int,input().aplit()))
    b,c=0,0
    yes = True
    for j in range(10):
        if a[j]>b:b=a[j]
        elif a[j]>c:c=a[j]
        else:yes=False
    print("YES" if yes else "NO")
