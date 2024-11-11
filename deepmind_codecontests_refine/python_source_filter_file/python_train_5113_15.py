n, s = input().split()
n, s = int(n), int(s)
s -= 1

first = list(map(int, input().split()))
second = list(map(int, input().split()))

if first[0] == 0:
    print('NO')
elif first[s] == 1:
    print('YES')
elif second[s] == 'NO':
    print('NO')
else:
    per = -1
    for i in range(s + 1, n):
        if first[i] == 1 and second[i] == 1:
            per = i
            break
    if per == -1:
        print('NO')
    else:
        print('YES')

