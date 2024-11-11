import sys

square = dict()
max_n = 32000
for i in range(1, max_n):
    square[i*i] = i

t = int(sys.stdin.buffer.readline().decode('utf-8'))
ans = ['-1']*t

for i in range(t):
    x = int(sys.stdin.buffer.readline().decode('utf-8'))
    if x == 1:
        continue
    for ni in range(1, max_n):
        y = ni**2 - x
        if y in square and ni**2 - (ni // (ni // square[y]))**2 == x:
            ans[i] = f'{ni} {ni // square[y]}'
            break

sys.stdout.buffer.write('\n'.join(ans).encode('utf-8'))
