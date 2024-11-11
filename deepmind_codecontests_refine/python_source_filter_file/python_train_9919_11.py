t = int(input())
for _ in range(t):
    a = [int(i) for i in input().split()]
    if(a[0]==1 or a[0]==2):
        print(1)
    else:
        x = a[1]-3
        print((x//a[1])+2) 