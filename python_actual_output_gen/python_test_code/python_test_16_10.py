for i in range(int(input())):
    a = [int(x) for x in input().split()]
    b = [int(x) for x in input().split()]
    ans = 0
    
    c21 = min(a[2], b[1])
    ans += 2 * c21
    a[2] -= c21; b[1] -= c21
    
    c02 = min(a[0], b[2])
    a[0] -= c02; b[2] -= c02
    
    c10 = min(a[1], b[0])
    a[1] -= c10; b[0] -= c10
    
    c22 = min(a[2], b[2])
    a[2] -= c22; b[2] -= c22
    
    c11 = min(a[1], b[1])
    a[1] -= c11; b[1] -= c11
    
    ans -= min(a[1], b[2])
    print(ans)