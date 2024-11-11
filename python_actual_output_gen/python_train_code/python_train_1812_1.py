num = int(input())

for i in range(num):
    l = input().split()
    f_n = int(l[0])
    s_n = int(l[1])

    if s_n%f_n != 0:
        print(s_n * (f_n//s_n + 1) - f_n)
    else:
        print(0)