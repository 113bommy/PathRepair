n = int(input())
strarr = []
for _ in range(n):
    strarr.append(input())
strarr.sort(key=lambda x: len(x))
flag = True
for i in range(n-1):
    if strarr[i] not in strarr[i+1]:
        flag = False
        break
if flag:
    print('Yes')
    for i in range(n):
        print(strarr[i])
else:
    print('NO')