def toosmall0(loc0, loc1, loc2, opt):
    if len(loc2)>opt:
        loc2.reverse()
        while (len(loc2)>opt) and (len(loc0)<opt):
            new = loc2.pop()
            loc0.append(new)
        loc0.sort()
        loc2.reverse()
    if len(loc1)>opt:
        loc1.reverse()
        while (len(loc1)>opt) and (len(loc0)<opt):
            new = loc1.pop()
            loc0.append(new)
        loc0.sort()
        loc1.reverse()
    return loc0, loc1, loc2

def toobig0(loc0, loc1, loc2, opt):
    if len(loc2)<opt:
        while (len(loc2)<opt) and (len(loc0)>opt):
            new = loc0.pop()
            loc2.append(new)
        loc0.sort()
    if len(loc1)<opt:
        while (len(loc1)<opt) and (len(loc0)<opt):
            new = loc0.pop()
            loc1.append(new)
        loc0.sort()
    return loc0, loc1, loc2

def f(s):
    opt = int(len(s)/3)
    loc0=[]
    loc1=[] 
    loc2=[] 
    for i, char in enumerate(s):
        if char=='0':
            loc0.append(i)
        elif char=='1':
            loc1.append(i)
        else:
            loc2.append(i)

    if len(loc0)<opt:
        loc0, loc1, loc2 = toosmall0(loc0, loc1, loc2, opt)
    elif len(loc0)>opt:
        loc0, loc1, loc2 = toobig0(loc0, loc1, loc2, opt)

    if (len(loc2)<opt) and (len(loc1)>opt):
        while (len(loc2)<opt) and (len(loc1)>opt):
            new = loc1.pop()
            loc2.append(new)
        loc2.sort()
    if (len(loc2)>opt) and (len(loc1)<opt):
        loc2.reverse()
        while (len(loc2)>opt) and (len(loc1)<opt):
            new = loc2.pop()
            loc1.append(new)
    output = [('0', el) for el in loc0]+[('1', el) for el in loc1]+[('2', el) for el in loc2]
    output.sort(key = lambda x: x[1])
    output = [el[0] for el in output]
    return ''.join(output)


n = int(input())
s = input()

output = f(s)
print(output)



