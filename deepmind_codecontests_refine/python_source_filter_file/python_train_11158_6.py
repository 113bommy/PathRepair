from itertools import permutations

n = int(input().strip())
s = input().strip()
t = input().strip()

#print(n, s, t)


def doEven(n, s, t):
    d = ['a', 'a', 'b', 'b', 'c', 'c']
    #print(d)
    filePerms = []
    for i in permutations(d):
        if i not in filePerms:
            filePerms.append(i)
    #print(filePerms)
    #print(len(filePerms))

    for i in range(len(filePerms)):
        filePerms[i] = ''.join(filePerms[i])
    #print(filePerms)
    cases = []
    #print(s, t)
    for i in filePerms:
        if s not in i and t not in i:
            cases.append(i)
    #print(cases)
    if n == 2:
        return cases[0]
    for i in cases:
        j = i + i
        if s not in j and t not in j and n % 2 == 0:
            return i
        flag[0] = 1


def doOdd(x, s, t):
    d = ['a', 'a', 'b', 'b', 'c', 'c']
    #print(d)
    filePerms = []
    for i in permutations(d):
        if i not in filePerms:
            filePerms.append(i)
    #print(filePerms)
    #print(len(filePerms))

    for i in range(len(filePerms)):
        filePerms[i] = ''.join(filePerms[i])
    #print(filePerms)
    cases = []
    #print(s, t)
    for i in filePerms:
        if s not in i and t not in i:
            cases.append(i)
    #print(cases)
    for i in cases:
        if x == 2:
            j = i
        else:
            j = i + i
        if s not in j and t not in j:
            options = ['abc', 'acb', 'bac', 'bca', 'cab', 'cba']
            for k in options:
                possible = k + i
                if s not in possible and t not in possible:
                    #print()
                    #print(k)
                    #print(i)
                    return k + int(x / 2) * i
            for k in options:
                possible = i + k
                if s not in possible and t not in possible:
                    #print()
                    #print(i)
                    #print(k)
                    return int(x / 2) * i + k
        flag[0] = 1


flag = [0]
if s[0] == t[0] and s[1] != t[1] and s[0] != s[1] and t[0] != t[1]:
    print('YES')
    print(n * s[1] + n * t[1] + n * s[0])
elif s[1] == t[1] and s[0] != t[0] and s[1] != s[0] and t[1] != t[0]:
    print('YES')
    print(n * s[1] + n * t[0] + n * s[0])
elif n == 1:
    options = ['abc', 'acb', 'bac', 'bca', 'cab', 'cba']
    for i in options:
        if s not in i and t not in i:
            print('YES')
            print(i)
            break

elif n % 2 == 0:
    solution = doEven(n, s, t)
    #print()
    #print(n, s, t)
    if flag[0] == 1:
        print('NO')
    else:
        print('YES')
        print(int(n / 2) * solution)
else:
    solution = doOdd(n - 1, s, t)
    #print()
    #print(n, s, t)
    if flag[0] == 1:
        print('NO')
    else:
        print('YES')
        print(solution)

