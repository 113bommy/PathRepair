n, k = map(int, input().split())
s = input()
letters = set(input().split())
mul = 0
cnt = 0

for letter in s:
    if letter in letters:
        mul += 1
    else:
        cnt += mul * (mul + 1) / 2
        mul = 0

if mul > 0:
    cnt += mul * (mul + 1) / 2

print(int(cnt))
