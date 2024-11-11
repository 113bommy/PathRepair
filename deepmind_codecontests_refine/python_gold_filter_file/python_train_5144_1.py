n, m = input().split()
nums = sorted(map(int, input().split()))
count = 0
money = 0
for num in nums:
    if (num < 0) and (count < int(m)):
        money += num * -1
        count += 1
print(money)

