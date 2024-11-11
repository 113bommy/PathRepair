cnt = (1 << 32) - 1
l = int(input().strip())
ans = 0
array = []
multiply = [1]
for i in range(l):
    line = input().strip()
    if line[0] == 'f':
        multiply.append(min(cnt, multiply[-1]*int(line[3:])))
        array.append(int(line[3:]))
    elif line[0] == 'e':
        multiply.pop()
        array.pop()
    elif line[0] == 'a':
        ans += multiply[-1]
if ans >= cnt:
    print('OVERFLOW!!!')
else:
    print(int(ans))