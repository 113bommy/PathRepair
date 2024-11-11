from collections import deque
num = int(input())
arr = deque(i for i in range(1, num**2+1))
cases = len(arr)//2
pairs = []
while cases:
    cases -= 1
    pairs.append([arr.popleft(), arr.pop()])
for i in range(num):
    temp = []
    while len(temp) < num:
        temp.extend(pairs.pop())
    print(*temp)


