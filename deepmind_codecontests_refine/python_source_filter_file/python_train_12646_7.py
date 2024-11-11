n = int(input())
s = input()
j = ord('A')

s = s.upper()

if n > 26:
    for i in range(26):
        if chr(j) in s:
            j += 1
        else:
            print('NO')
            exit()
    print('YES')
else:
    print('NO')
