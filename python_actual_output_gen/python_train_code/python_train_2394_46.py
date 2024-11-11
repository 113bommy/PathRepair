n = int(input())
a = list(map(int, input().split()))
a = sorted(a)

total = 0
ok = 0
for i in range(len(a)):
    # print(a[i], total, ok)
    if a[i] >= total:
        ok += 1
        
    total += a[i]
    
print(ok)