#01 Game
t = int(input())
for i in range(t):
    s = input()
    c = 0
    while True:
        if '01' in s:
            s = s.replace('01','',1)
            c+=1
        elif '10' in s:
            s = s.replace('10','',1)
            c+=1
        else:
            break
    if c%2!=0:
        print('DA')
    else:
        print('NET')
        