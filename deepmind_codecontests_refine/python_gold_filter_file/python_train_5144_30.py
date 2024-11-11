n, m = [int(i) for i in input().split()]
arr = [int(i) for i in input().split()]
arr = sorted(arr)

count = 0
tot = 0
for a in arr:
    if a<0:
        tot -= a
        count += 1
    if count == m or a>=0:
        break
    
    
print(tot)