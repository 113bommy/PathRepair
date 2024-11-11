n = int(input())
ws = list(map(int, input().split(' ')))

res = 10 ** 10
def f(vs):
    return sum(abs(a - b) for a, b in zip(vs[0::2], vs[1::2]))

for i in range(len(ws)):
    for j in range(i + 1, len(ws)):
        test = ws[:i] + ws[i+1:j] + ws[j+1:]
        res = min(res, f(test))

print(res)
