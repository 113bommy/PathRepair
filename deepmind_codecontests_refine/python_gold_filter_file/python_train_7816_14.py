n = int(input())
colors = input()
if n==1:
    print('YES')
else:
    for i in colors:
        if (colors.count(i)) > 1:
            print('YES')
            exit()
    print('NO')