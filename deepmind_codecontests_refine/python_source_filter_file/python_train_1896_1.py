n = input()
n = int(n)
s = list(map(lambda x: int(x),input().split()))
for num in s:
    if num >= 15 and num%14 <= 6:
        print('YES')
    else:
        print('NO')