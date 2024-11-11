for _ in range(int(input())):
    l,r=map(int,input().split())
    print("YES" if r<2*l else "NO")