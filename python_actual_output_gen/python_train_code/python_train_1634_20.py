def solve(s):
    if(len(s)==0):
        return s
    if(len(s)==1 and s.islower()):
        return s.upper()
    if(s.isupper()):
        return s.lower()
    if(s[0].islower() and s[1:].isupper()):
        return s[0].upper()+s[1:].lower()
    return str
s = input()
print(solve(s))