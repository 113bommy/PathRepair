n, m = [int(x) for x in input().split()]

cuts = min(n // 2, m)
grps = cuts
rem = max(0, m - cuts - n % 2)
print(max(0, grps - rem))
    
