t = list(input())
s = int(t[0]) + int(t[1]) + int(t[2])
s1 = int(t[3]) + int(t[4])+ int(t[5])

def first(s, s1, t): #mnijsza lewa
    t = t[:3]
    todo = s1 - s
    if 9 - int(min(t, key=lambda x: int(x))) < todo:
        small = 9 - int(min(t[:2], key=lambda x: int(x)))
        t.remove(min(t, key=lambda x: int(x)))

        if 9 - int(min(t, key=lambda x: int(x))) + small < todo:
            return 3
        else:
            return 2

    else:
        return 1

def secend(s, s1, t): #mnijsza prawa 
    t = t[3:]
    todo = s - s1
    if 9 - int(min(t, key=lambda x: int(x))) < todo:
        smaller = 9 - int(min(t, key=lambda x: int(x)))
        t.remove(min(t, key=lambda x: int(x)))

        if 9 - int(min(t, key=lambda x: int(x))) + smaller < todo:
            return 3

        else:
            return 2
    else:
        return 1

def third(s, s1, t): #większa lewa
    t = t[:3]
    todo = s - s1
    if int(max(t, key=lambda x: int(x))) < todo:
        small = int(max(t, key=lambda x: int(x)))
        t.remove(max(t, key=lambda x: int(x)))

        if int(max(t, key=lambda x: int(x))) + small < todo:
            return 3

        else:
            return 2

    else:
        return 1


def fourth(s, s1, t): #większa prawa
    t = t[3:]
    todo = s1 - s
    if int(max(t, key=lambda x: int(x))) < todo:
        small = int(max(t, key=lambda x: int(x)))
        t.remove(max(t, key=lambda x: int(x)))

        if int(max(t, key=lambda x: int(x))) + small < todo:
            return 3

        else:
            return 2

    else:
        return 1

def fifth(s, s1, t): #większa prawa
    todo = s1 - s
    if int(max(t[3:], key=lambda x: int(x))) + (9 - int(min(t[:3], key=lambda x: int(x)))) > todo:
        return 2
    
    else:
        return 3
        
def sixth(s, s1, t): #większa lewa
    todo = s - s1
    if int(max(t[:3], key=lambda x: int(x))) + (9 - int(min(t[3:], key=lambda x: int(x)))) > todo:
        return 2
    
    else:
        return 3

if s != s1:
    if s > s1:
        print(min(third(s, s1, t), secend(s, s1, t), sixth(s, s1, t)))

    else:
        print(min(fourth(s, s1, t), first(s, s1, t), fifth(s, s1, t)))

else:
    print(0)