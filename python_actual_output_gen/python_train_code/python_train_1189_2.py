a, b = map(int, input().split())
s = input()
i = 1
t = ''
if (a == 1) and (b > 0):
    print('0')
    exit()
elif a == 1:
    print('1')
    exit()
if (s[0] != '1') and (b != 0):
    t += '1'
    b -= 1
else:
    t += s[0]
for i in range(1,len(s)):
    if (s[i] != '0') and (b > 0):
        t += '0'
        b-1
    else:
        t += s[i]
print(t)