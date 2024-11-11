def password(str):
    lst = [0]*len(str)
    n = 0
    for i in range(1, len(str)):
        while n > 0 and str[n] != str[i]:
            n = lst[n - 1]
        if str[n] == str[i]:
            n += 1
            lst[i] = n
        else:
            lst[i] = n
    return lst



x = None
in_c = input()
lst = password(in_c)
var = lst[len(in_c) - 1]
if var != 0:
    for j in range(2):
        for i in range(1, len(in_c) - 1):
            if var == lst[i]:
                x = False
                break
        if not x:
            var = lst[var-1]
            if var == 0:
                break
        else:
            break
if not x or var == 0:
    print("Just a legend")
else:
    print(in_c[0:var])