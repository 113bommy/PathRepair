# for _ in range(int(input())):
n, s = list(map(int, input().split()))
sum = 0
if n >= s:
    print(1)
else:
    if s/n != 0:
        print(s//n + 1)
    else:
        print(s//n)




