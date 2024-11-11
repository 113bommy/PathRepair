n = int(input())
L = [int(x) for x in input().split()]
PartialL = [L[0]]
PartialR = [L[-1]]
for i in range(1,n):
    PartialL.append(PartialL[-1]+L[i])
    PartialR.append(PartialR[-1]+L[-i-1])

ans = 0
for i in range(n-1):
    temp = PartialL[i]
    low = 0
    high = n-i
    while high-low > 1:
        guess = (high+low)//2
        if PartialR[guess] > temp:
            high = guess
        elif PartialR[guess] < temp:
            low = guess
        else:
            ans = temp
            break
    if PartialR[high] == temp:
        ans = temp
    elif PartialR[low] == temp:
        ans = temp

print(ans)