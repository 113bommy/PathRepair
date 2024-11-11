def solve(n, k, z, a):
    answ = sum(a[:k+1])
    for t in range(z+1):
        max_sum = 0
        s = 0
        for i in range(k-2*t+1):
            s1 = 0 if i+1 >= len(a) else a[i+1]+a[i]
            if s1 > max_sum:
                max_sum = s1
            s += a[i]
        if max_sum * t + s > answ:
            answ = max_sum * t + s
    print(answ)
        
            

t = int(input())
for i in range(t):
    n, k, z = map(int, input().split())
    a = [int(j) for j in input().split()]
    solve(n, k, z, a)
    
