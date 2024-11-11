a = input()
if (a[0] == "a" or a[0] == "h") and (a[1] == "1" or a[1] == "8"):
    print(3)
elif ((a[0] == "b" or a[0] == "c" or a[0] == "d" or a[0] == "d" or a[0] == "e" or a[0] == "f" or a[0] == "g") and (a[1] == "1" or a[1] == "8")) or ((a[0] == "a" or a[0] == "h") and int(a[1] in range(2, 8))):
    print(5)
else:
    print(8)