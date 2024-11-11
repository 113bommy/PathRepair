l = [1, 1]
n = int(input())
s = ''

def fib(l, n):
    while len(l) <= n and l[-1] + l[-2] <= n + 1:
        l.append(l[-1] + l[-2])
        fib(l, n)

fib(l, n)

for i in range(1, n + 1):
    if i in l:
        s += 'O'

    else:
        s += 'o'

print(s)
#
