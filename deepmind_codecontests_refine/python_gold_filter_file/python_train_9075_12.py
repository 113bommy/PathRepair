n = input()
a4 = n.count('4')
a7 = n.count('7')

if a4 + a7 == 0:
    print(-1)
elif a4 >= a7:
    print(4)
else:
    print(7)