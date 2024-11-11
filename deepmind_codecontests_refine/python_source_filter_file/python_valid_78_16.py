T = int(input())

for t in range(T):
    l,r = map(int, input().split())
    if ((r+1)//2)-1>= l and ((r+1)//2)-1<= r:
        print(((r+1)//2)-1)
    else:
        print(r%l)