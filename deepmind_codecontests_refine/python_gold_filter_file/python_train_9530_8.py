amount = int(input())
found = False
for i in range(amount):
    if not found:
        name, before, after = map(str, input().split())
        before = int(before)
        after = int(after)
        if 2400 <= before < after:
            found = True
            break
print('YES' if found else 'NO')
