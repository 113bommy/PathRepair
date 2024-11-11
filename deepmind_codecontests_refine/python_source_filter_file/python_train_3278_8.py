__author__ = 'Andrey'
n = int(input())
s_n = str(n)
l_n = len(s_n)
done = False
for x in range(l_n):
    n_1 = int(s_n[x])
    if n_1 % 8 == 0:
        print("YES")
        print(n_1)
        break
    for y in range(x, l_n):
        n_2 = int(s_n[y])
        n_12 = int(str(n_1) + str(n_2))
        if n_1 != 0 and n_12 % 8 == 0:
            print("YES")
            print(n_12)
            done = True
            break
        for z in range(y, l_n):
            n_3 = int(s_n[z])
            n_123 = int(str(n_12) + str(n_3))
            if n_1 != 0 and n_123 % 8 == 0:
                print("YES")
                print(n_123)
                done = True
                break
        if done:
            break
    if done:
        break
else:
    print("NO")