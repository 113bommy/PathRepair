t = int(input())

for _ in range(t):
    p = sorted([i for i in input()])
    h = [i for i in input()]
    
    ok = False

    for i in range(len(h)-1):
        for j in range(i+1, len(h)+1):
            st = sorted(h[i:j])
#             print(st)
            if p == st:
                ok = True
                break
    print("YES" if ok else "NO")
