from collections import deque

a = sorted(input())
l = len(a)
a = deque(a[:(len(a)+1)//2])
b = sorted(input())
b = deque(b[len(b)-len(b)//2:])
# print(a, b)

result = ["0"] * l
left = -1
right = l

while left <= right:
    if len(b) == 0:
        result[left+1] = a[0]
        break
    if a[0] > b[-1]:
        right -= 1
        result[right] = a[-1]
        a.pop()
    else:
        left += 1
        result[left] = a[0]
        a.popleft()
    # print(result)
    #print(left, right)
    if len(a) == 0:
        result[left+1] = b[0]
        break
    if a[0] > b[-1]:
        right -= 1
        result[right] = b[0]
        b.popleft()
    else:
        left += 1
        result[left] = b[-1]
        b.pop()
    # print(result)
    # print(left, right)

print("".join(result))