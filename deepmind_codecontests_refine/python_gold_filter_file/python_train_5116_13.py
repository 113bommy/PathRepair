n, h = [int(x) for x in input().split()]
nums = [int(x) for x in input().split()]

lb, rb = 0, n + 1

while rb - lb > 1:
    mb = (lb + rb) >> 1
    
    if mb == n + 1:
        rb = mb
        continue
    
    bottles = sorted(nums[:mb], reverse=True)
    stat = sum(bottles[i] for i in range(0, len(bottles), 2))
    if stat <= h:
        lb = mb
    else:
        rb = mb
print(lb)

