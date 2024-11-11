def res(a, b):
    if a == '8<' and b == '[]':
        return 1
    elif a == '8<' and b == '()':
        return -1
    elif a == '8<' and b == '8<':
        return 0
    elif a == '[]' and b == '8<':
        return -1
    elif a == '[]' and b == '()':
        return 1
    elif a == '[]' and b == '[]':
        return 0
    elif a == '()' and b == '8<':
        return 1
    elif a == '()' and b == '[]':
        return -1
    elif a == '()' and b == '()':
        return 0

s1 = input()
s2 = input()

s1 = [s1[i:i+2] for i in range(0, len(s1), 2)]
s2 = [s2[i:i+2] for i in range(0, len(s2), 2)]

sum = 0
for i in zip(s1, s2):
    sum += res(*i)

if sum > 0:
    print('TEAM 1 WINS')
if sum < 0:
    print('TEAM 2 WINS')
else:
    print('TIE')