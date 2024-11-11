s = input()
k = int(input())

if len(s) < k:
    print('Impossible')
else:
    a = set()
    c = 0
    for i in s:
        if not i in a:
            c += 1
            a.add(i)
    print(max(0,k-c))