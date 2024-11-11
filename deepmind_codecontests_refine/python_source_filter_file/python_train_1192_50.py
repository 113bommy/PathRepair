klava = 'qwertyyuiopasdfghjkl;zxcvbnm,./'
if input() == 'R':
    s = input()
    sr = ''
    for i in range(len(s)):
        sr += klava[klava.find(s[i]) - 1]
    print(sr)
else:
    s = input()
    sr = ''
    for i in range(len(s)):
        sr += klava[klava.find(s[i]) + 1]
    print(sr)
