t = int(input())

for _ in range(t):
    n = int(input())
    v = []
    for _ in range(n):
        temp = list(map(int,input().split()))
        v.append(temp)
    
    taken = {}
    firstMissed = -1
    for i, l in enumerate(v, 1):
        found = False
        for princess in l:
            if princess not in taken:
                taken[princess] = 0
                found = True
                break
        if not found and firstMissed == -1:
            firstMissed = i
    
    if firstMissed == -1:
        print("OPTIMAL")
    else:
        print("IMPROVE")
        print(firstMissed, [i for i in range(1, n + 1) if i not in taken][0])
            
        