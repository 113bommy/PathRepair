n = input()
m = 0
a_c = n.count('a')
if a_c > len(n) / 2:
    print(len(n))
else:
    if a_c != 1:
        print(a_c + a_c - 1)
    else:
        print(a_c)
