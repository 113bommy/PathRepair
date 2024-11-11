a = [2, 7, 2, 3, 3, 4, 2, 5, 1, 2]
s = input()
if len(s) == 1:
    print(a[int(s[0])])
else:
    print(a[int(s[0])] + a[int(s[1])])