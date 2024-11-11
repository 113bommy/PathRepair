n = int(input())
for t in range(n):
    a = int(input())
    b = list(map(int,input().split()))
    for i in range(n-2):
        if b[i] in b[i+2:]:
            a = -1
            break
    print("YES" if a==-1 else "NO")
