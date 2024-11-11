for i in range(int(input())):
    n = int(input())
    a = list(map(int,input().split()))
    ok = False
    for i in range(n-2):
            if a[i] in a[i+2:]:
                ok = True
                break
    print("YES" if ok else "NO")   
    