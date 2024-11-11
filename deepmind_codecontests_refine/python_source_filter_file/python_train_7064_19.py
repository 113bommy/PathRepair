s = input()
a = s.find('C')

if a == -1:
    print("No")
else:
    if s[a:].find('F') == -1:
        print("No")
    else print("Yes")