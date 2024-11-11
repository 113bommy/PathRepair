
def solve(length, num):
    for i in range(0, length // 2):
        if num[i] == '0':
            return [[i + 1, length], [i + 2, length]]
    
    s = length // 2

    if length % 2 == 1:
        s += 1

    for i in range(s, length):
        if num[i] == '0':
            return [[1, i + 1], [1, i]]
    
    if length % 2 == 0:
        return [[1, length // 2], [length // 2 + 1, length]]
    else:
        return [[1, length // 2 + 1], [length // 2 + 1, length]]

t = int(input())

for i in range(t):
    l = int(input())
    s = input()

    ans = solve(l, s)

    print(f"{ans[0][0]} {ans[0][1]} {ans[1][0]} {ans[1][1]}")

    