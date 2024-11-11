n, k = map(int, input().split())
arr = list(map(int, input().split()))
counterS = 0
counterL = 0

for i in arr:
    if i <= k:
        counterS += 1
    else:
        if i <= 2 * k:
            counterL += 1
        else:
            counterL += (i // (2 * k))
            y = i - (i // (2 * k))*k
            if y <= k:
                if y != 0:
                    counterS += 1
            else:
                counterL += 1
lastCounter = (counterS // 2) + (counterS % 2) + counterL
print(lastCounter)
