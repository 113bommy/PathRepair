n = int(input())
S = [v for v in input()]

# determine L or R
lst = [0 for i in range(2 * n)]
for i in range(2 * n):
    if S[i] == 'W' and (2 * n - i - 1) % 2 == 0:
        lst[i] = 'L'
    elif S[i] == 'W' and (2 * n - i - 1) % 2 == 1:
        lst[i] = 'R'
    elif S[i] == 'B' and (2 * n - i - 1) % 2 == 0:
        lst[i] = 'R'
    elif S[i] == 'B' and (2 * n - i - 1) % 2 == 1:
        lst[i] = 'L'


deq = 0
val = 1
#tracing lst
for i in range(2 * n):
    if lst[i] == 'L':
        deq += 1
    elif lst[i] == 'R':
        val *= deq
        val %= 10 ** 9 + 7
        deq -= 1

if deq != 0:
    print(0)
else:
    for i in range(1, n + 1):
        val = val * i % (10 ** 9 +7)
    print(val)
