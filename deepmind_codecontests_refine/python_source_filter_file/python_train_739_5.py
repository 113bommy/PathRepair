import sys

data = sys.stdin.read().splitlines()

n = int(data[0])

nums = [int(line) for line in data[1:]]

end = 1 << n

for cur in range(end):
    cnt = 0
    for i in range(n):
        if cur & (1 << i):
            cnt += nums[i]
        else:
            cnt -= nums[i]
    if cnt == 0:
        print("YES")
        break
else:
    print("NO")
