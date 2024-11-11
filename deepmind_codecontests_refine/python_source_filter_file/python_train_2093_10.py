n = int(input())
s = input()
sm = (sum(map(int, list(s))))
dv = 2
ans = []
while dv * dv <= sm:
    if sm % dv == 0:
        summ = 0
        tmp = True
        for i in range(len(s)):
            summ += int(s[i])
            if summ == sm // dv:
                summ = 0
            elif summ > sm // dv:
                tmp = False
        if tmp:
            ans.append(1)
    dv += 1
if ans:
    print('YES')
else:
    print('NO')