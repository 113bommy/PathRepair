for _ in range(int(input())):
    s = input()
    h = input()
    n = len(s)
    for i in range(n):
        if sorted(h[i:i+n])==sorted(s):
            print("YES")
            break
    else:
        print("NO")