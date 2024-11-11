def antipal (s) :
    if s != s[::-1] :
        return len(s)
    else:
        while s[-1] == s[0] and len(s) != 1:
            s = s[:-1]
        if len(s) == 1:
            return 0
        else:
            return len(s)


s = input()
print (antipal(s))
