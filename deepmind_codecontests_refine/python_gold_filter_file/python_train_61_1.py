string = input().strip()
flag, f1, f2 = False, False, False
ins = []
for _ in range(int(input())):
    ins.append(input().strip())
for i in ins:
    if i == string or i == string[::-1]:
        print('YES')
        exit()
    if i[0] == string[1]:
        f1 = True
    if i[1] == string[0]:
        f2 = True
if f1 and f2:
    print('YES')
else:
    print('NO')