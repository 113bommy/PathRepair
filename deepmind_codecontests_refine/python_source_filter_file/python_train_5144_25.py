amount, carry = map(int, input().split())
prices = list(map(int, input().split()))
ans = 0
for x in prices:
    if carry == 0:
        break
    if x < 0:
        ans += abs(x)
        carry -= 1
print(ans)