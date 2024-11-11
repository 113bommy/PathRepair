N = int(input())

mem = [0] * N
for i in range(N):
    s = input()
    x = 0
    y = 0
    for j in range(len(s)):
        if s[j] == '(':
            x += 1
        else:
            x -= 1
            y = min(x, y)
    mem[i] = (x, y)

mem_a = sorted([ele for ele in mem if ele[0] > 0], key=lambda x: -x[1])
mem_b = sorted([ele for ele in mem if ele[0] <= 0], key=lambda x: -x[1])

ans = True
val = 0
for ele in mem_a:
    if val + ele[1] < 0:
        ans = False
    val += ele[0]
for ele in mem_b:
    if val + ele[1] < 0:
        ans = False
    val += ele[0]


YesNo = lambda tf: print('Yes') if tf else print('No')
YesNo(ans and val == 0)