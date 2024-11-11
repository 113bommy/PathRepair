while(1):
    a = input()
    if a.split()[1] == "?":
        break
    eval("print("+a+")")
