import sys
input = sys.stdin.readline

a,b = list(map(int, input().split()))
n = list(map(int, input().split()))
n = n + n
#print(len(n))

best = 0

left = 0
right = 0

total_cost = 0
total_days = 0

for i in range(len(n)):
    x = n[i]
    total_cost += (x*(x+1)) // 2
    total_days += x
    
    if total_days > b:
        over = total_days - b
        over_cost = (over * (over + 1)) // 2
        
        while over > n[left]:
            x = n[left]
            reduce = (x*(x+1)) // 2
            total_cost -= reduce
            total_days -= x
            left += 1
            over = total_days - b
            over_cost = (over * (over + 1)) // 2
        
        if over < n[left]:
            best = max(best, total_cost - over_cost)
            
print(best)