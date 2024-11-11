a, b = map(int, input().split())
arr = []
for i in range(a):
    arr += input().split()[1:]
print('YES' if len(set(arr)) == b else 'NO')