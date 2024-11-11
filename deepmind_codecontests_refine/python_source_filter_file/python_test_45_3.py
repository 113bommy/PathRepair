
    
t = int(input())
for _ in range(t):
    n = int(input())
    l = list(map(int, input().split(' ')))
    i = 0
    height = 1
    while (i < n):
        if (i == 0):
            if (l[i] == 1):
                height += 1
        else:
            if (l[i] == 1 and l[i-1] == 1):
                height += 5
            elif (l[i] == 1):
                height += 1
            elif (l[i] == 0 and l[i-1] == 0):
                print(-1)
                i = n
        i += 1
    print(height)

    
    


