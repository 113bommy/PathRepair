def Sol(s):
    i=0
    while i < len(s)-2:
        if s[i] == '1':
            if s[i+1] == '4':
                if s[i+2] == '4':
                    s = s[3:]
                else:
                    s = s[2:]
            else:
                s = s[1:]
        else:
            print("NO")
            return
    if len(s) == 0:
        print("YES")
        return
    elif len(s) == 1:
        if s == '1':
            print("YES")
            return
        else:
            print("NO")
            return
    else:
        if s == '14' or '11':
            print("YES")
            return
        else:
            print("NO")
            return

n= input()
Sol(n)