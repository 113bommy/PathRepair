for i in range(int(input())):
    n, k, d = map(int, input().split())
    a = list(map(int, input().split()))
    s = d
    for j in range(n - d + 1):
        set_a = set(a[j: j + d + 1])
        if s > len(set_a):
            s = len(set_a)
    print(s)
        
        

