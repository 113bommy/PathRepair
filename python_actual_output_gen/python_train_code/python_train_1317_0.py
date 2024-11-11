n = int(input())
ls = list(map(int, input().split()))
months = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31] + [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31] + [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31] + [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
found = False
for i in range(len(months) - n + 1):
    if ls == months[i:i+n]:
        found = True
print(['NO', 'YES'][found])
