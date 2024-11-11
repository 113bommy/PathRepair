s = input()
k = int(input())
if k > len(s):
    print('NO')
else:
    l_sub = len(s) // k
    
    if len(s) % l_sub != 0:
        print('NO')
    else:
        l = []
        i = 0
        x = l_sub
        while i != len(s):
            l.append(s[i : x])
            i += l_sub
            x = x + l_sub
        if (all(i == i[::-1] for i in l)):
            print('YES')
        else:
            print('NO')