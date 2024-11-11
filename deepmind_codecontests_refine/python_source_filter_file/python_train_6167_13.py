q = int(input())
for _ in range(q):
    input()
    x = input()
    ans1 = ['1']
    ans2 = ['1']
    is_one = False

    for i in x[1:]:
        if i == '0':
            ans1.append('0')
            ans2.append('0')
        elif i == '1':
            if is_one:
                ans1.append('0')
                ans2.append('1')
            else:
                ans1.append('1')
                ans2.append('1')
                is_one = True
        else:
            if is_one:
                ans1.append('0')
                ans2.append('2')
            else:
                ans1.append('1')
                ans2.append('1')
    for i in ans1:
        print(i, end='')
    print()
    for i in ans2:
        print(i, end='')
    print()
    