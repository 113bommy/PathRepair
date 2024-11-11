n = int(input())
# x, y = map(int, input().split())

nums = {'4': 0, '8': 1, '15': 2, '16': 3, '23': 4, '42': 5}


def convert(x):
    return nums[x]


l = list(map(convert, input().split()))

c = [0] * 6
rm = 0

for x in l:
    if x == 0:
        c[x] += 1
    elif c[x - 1] > 0:
        c[x] += 1
        c[x - 1] -= 1

print(c)
print(n - (c[5] * 6))
