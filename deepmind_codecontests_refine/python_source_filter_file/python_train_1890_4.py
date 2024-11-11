t = input()

last_a = -1
s1 = ''

for i in range(len(t)):
    if t[i] == 'a':
        last_a = i

fim = False

if last_a == -1 and (len(t) % 2 != 0 or t[:(len(t)//2)+1] != t[(len(t)//2)+1:]):
    print(':(')
    fim = True
else:
    for i in range(last_a):
        if t[i] != 'a':
            s1 += t[i]
    if len(s1) == (len(t) - last_a - 1):
        if s1 == t[last_a+1:]:
            print(t[:last_a+1])
            fim = True
    elif len(s1) > (len(t) - last_a - 1):
        print(':(')
        fim = True
    else:
        last_a += 1
        while True:
            if last_a >= len(t): break
            s1 += t[last_a]
            if len(s1) == (len(t) - last_a - 1): break
            last_a += 1
        if s1 == t[last_a+1:]:
            print(t[:last_a+1])
            fim = True
        else:
            print(':(')
            fim = True

if not fim: print(':(')

