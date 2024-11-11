n=int(input())
for _ in range(n):
    l = list(map(int,input().split()))
    r = l[1]//l[0]
    d = l[1]%l[0]
    f = (d**2)*d+(l[0]-d)*(r**2)
    print(f)