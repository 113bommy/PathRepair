
def word(s):
    c = 0
    for i in s:
        if 97>=ord(i)<=122:
            c += 1
        else:
            c -= 1
    if c >=0 :
        return s.lower()
    return s.upper()



print(word(input()))