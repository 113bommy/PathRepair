t=int(input())
for i in range(t):
    a=[int(x) for x in input().split()]
    if a[0]==a[2] or a[1]==a[3]:
        print(max(a[2]-a[0]+a[3]-a[1],-(a[2]-a[0]+a[3]-a[1])))
    else:
        print(max(a[2]-a[0],a[0]-a[2])+max(a[3]-a[1],a[3]-a[1])+2)