n = int(input())
a = list(map(int,input().split()))
a.sort()
a.append(1000)
b = []
for i in range(n):
    if a[i]!=a[i+1]:
        b.append(a[i])
if len(b)>3:
    print(-1)
else:
    if len(b)==3:
        b.sort()
        if abs(b[1]-b[0])==abs(b[1]-b[2]):
            print(abs(b[1]-b[2]))
        else:
            print(-1)
    elif len(b)==2:
        m = abs(a[0]-a[1])
        if m%2==0:
            print(m//2)
        else:
            print(m)
    else:
        print(0)
