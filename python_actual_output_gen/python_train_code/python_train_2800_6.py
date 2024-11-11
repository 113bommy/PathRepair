test = int(input())

for _ in range(test):
    space = input()
    a1, a2 = map(int, input().split())
    b1, b2 = map(int, input().split())
    f1, f2 = map(int, input().split())
    
    ans = 0
    if a1 == b1 == f1:
        if a2 < f2 < b2 or b2 < f2 < a2:
            ans = abs(a2 - b2) + 2 
        else:
            ans = abs(a2 - b2)
    elif a2 == b2 == f2:
        if a1 < f1 < b1 or b1 < f1 < f1:
            ans = abs(a1 - b1) + 2 
        else:
            ans = abs(a1 - b1)
    else:
        ans = abs(a1 - b1) + abs(a2 - b2)
    print(ans)