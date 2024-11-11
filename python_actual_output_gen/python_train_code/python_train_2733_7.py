d = {
    '2': [2],
    '3': [3],
    '4': [3, 2, 2],
    '5': [5],
    '6': [5, 3],
    '7': [7],
    '8': [7, 2, 2, 2, 2],
    '9': [7, 3, 3, 2]

}
n = int(input())
x = input()
a = []
for i in x:
    if i not in d:
        continue
    a += d[i]
print(''.join(map(str, sorted(a, reverse=True))))