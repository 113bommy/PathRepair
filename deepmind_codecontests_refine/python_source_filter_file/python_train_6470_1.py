def howmanyeights(s):
    return len([char for char in s if char == '8'])

n = int(input())
s = input()
if howmanyeights(s[:-10]) >= (n-10) // 2:
    print('YES')
else:
    print('NO')