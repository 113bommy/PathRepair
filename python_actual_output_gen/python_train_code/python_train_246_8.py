from sys import stdin

n = int(stdin.readline().rstrip())

diff = [0, 0, 0, 0, 0]

for x in stdin.readline().rstrip().split(' '):
    diff[int(x) -1] += 1
for x in stdin.readline().rstrip().split(' '):
    diff[int(x) -1] -= 1

result = 0

for k in diff:
    if (k % 2 == 1):
        print(-1)
        break
    else:
        if (k > 0):
            result +=k
print(result//2)
