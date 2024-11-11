n = int(input())
max_height = max(map(int, input().split()))
for i in range(n - 1):
    for h in sorted(map(int, input().split()), reverse = True):
        if h <= max_height:
            max_height = h
            break
    else:
        print("NO")
        break
else:
    print("YES")
    
    
