import sys
data = (sys.stdin.readlines())
berland = data[0].strip()
birland = data[1]
answer = ''
for i in range(len(berland)):
    answer += berland[len(berland) - i - 1]
if answer == birland:
    print('YES')
else:
    print('NO')