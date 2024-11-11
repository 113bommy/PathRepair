q = int(input())

for j in range(q):
    n = int(input())
    a = list(map(int, input().split()))
    
    counter = [0] * (n + 1)
    
    for i in range(n):
        counter[a[i]] += 1
        
    counter = sorted(counter)
    #print(counter)
    ans = counter[n]
    count = counter[n]
    
    for i in range(n - 1, -1, -1):
        if (count <= 0):
            break
        
        if (counter[i] >= count):
            count -= 1
            
        if (counter[i] < count):
            count = counter[i]
            
        ans += count
        
    print(ans)