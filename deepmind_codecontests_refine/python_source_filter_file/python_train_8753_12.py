n, k, s = map(int, input().split())

if s > (n-1) * k:
    print("NO")
    exit(0)
print("YES")

odd = 1
house = 1
while s > k and k > 0:
    dist = min(s-k+1, n-1)
    if odd:
        house = house+dist
        print(house, end=' ')
    else:
        house = house - dist
        print(house, end=' ')
    odd ^= 1
    s-= dist
    k -=1

while k>0:
    if odd:
        house += 1
        print(house, end=' ')
    else:
        house -= 1
        print(house, end=' ')
    odd ^= 1
    k -= 1

print()
