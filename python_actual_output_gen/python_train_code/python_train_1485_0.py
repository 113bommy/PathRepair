a = [x for x in input().split()]
if a[0] == a[1] == a[2]:
    print(0)
elif a[0] == a[1] or a[1] == a[2] or a[0] == a[2]:
    print(1)
else:
    if a[0][1] == a[1][1] == a[2][1] and (abs(int(a[0][0]) - int(a[1][0])) == abs(int(a[1][0]) - int(a[2][0])) == 1):
        print(0)
    elif ((abs(int(a[1][0]) - int(a[0][0])) == 1 or abs(int(a[1][0]) - int(a[0][0])) == 2) and a[1][1] == a[0][1]) or ((int(a[2][0]) - int(a[1][0]) == 1 or int(a[2][0]) - int(a[1][0]) == 2) and a[2][1] == a[1][1]) or ((abs(int(a[2][0]) - int(a[0][0])) == 1 or abs(int(a[2][0]) - int(a[0][0])) == 2) and a[2][1] == a[0][1]):
        print(1)
    else:
        print(2)
