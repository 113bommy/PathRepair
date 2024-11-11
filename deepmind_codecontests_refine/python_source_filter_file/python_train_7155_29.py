row = input()
length = len(row)
if length < 3:
    print("No")
else:
    found = False
    for index in range(1, length - 2):
        if (row[index - 1] != '.') and (row[index] != '.') and (row[index + 1] != '.') and (row[index - 1] != row[index]) and (row[index - 1] != row[index + 1]) and (row[index] != row[index + 1]):
            print("Yes")
            found = True
            break
    if not found:
        print("No")