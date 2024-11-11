n = int(input())

ans = [0,1,1,2]


if n == 0:
    print("0 0 0")
elif n == 1:
    print("0 0 1")
elif n == 2:
    print("0 1 1")
else:
    while ans[-1] + ans[-2] != n:
        ans.append(ans[-1] + ans[-2])

print('{} {} {}'.format(ans[-4], ans[-3], ans[-1]))