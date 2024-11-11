n = int(input())
cost = list(map(int, input().split()))
if n < min(cost):
    print(-1)
else:
    min_cost = min(cost)
    digits = n//min_cost
    extra = n - digits*min_cost
    ans = [9 - list(reversed(cost)).index(min_cost)] * digits
    #print(ans)
    idx = 0
    print(extra)
    while extra > 0 and idx < len(ans):
        found = False
        for i in range(9):
            if extra >= cost[i] - min_cost:
                largest = i
                found = True
        if not found:
            break
        extra -= cost[largest] - min_cost
        ans[idx] = largest + 1
        idx += 1
    print(''.join(str(i) for i in ans))