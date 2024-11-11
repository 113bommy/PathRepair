def a_maker(b):
    a = ''
    if len(b) == 2:
        a = b
    else:
        a += b[:2]
        for i in range(3, len(b), +2):
            a += b[i]
    return a


for i in range(int(input())):
   print(a_maker(input()))
