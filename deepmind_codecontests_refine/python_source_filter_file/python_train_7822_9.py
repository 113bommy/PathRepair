n = int(input())
a = list(map(int, input().split()))
s = []
left, right, last = 0, -1, 0

while left <= len(a) + right:
    # print(a, last, left, right)
    if last < a[left] and (a[left] < a[right] or a[right] < last):
        s.append('L')
        last = a[left]
        left += 1
    elif last < a[right] and (a[right] < a[left] or a[left] < last):
        s.append('R')
        last = a[right]
        right -= 1
    else:
        break

print(left - right - 1)
print(''.join(s))
