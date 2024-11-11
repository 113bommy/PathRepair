for _ in range(int(input())):
    a,b,c=map(int,input().split())
    l=sorted([a,b,c])
    print(max(0,2*(l[2]-l[0])-4))