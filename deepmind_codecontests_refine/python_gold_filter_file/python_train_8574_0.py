def escape(s):
    for i in range(len(s)):
        if s[i]=="r":
            print(i+1)
    for i in range(len(s)-1,-1,-1):
        if s[i]=="l":
            print(i+1)
    return ""
print(escape(input()))