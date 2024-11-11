m = int(input())
def findCoor(S):
    f,s,t = False,False,False
    a,b,c = "","",""
    for i in S:
        if i == '(': f = True
        elif i == '+': s = True
        elif i == ')' or i == '/': t = True
        elif t: c += i 
        elif s: b += i
        elif f: a += i
    return int((int(a) + int(b))/(int(c)))

dic = {}; value = []
for i in range(m):
    s = str(input())
    n = findCoor(s)
    value.append(n)
    if n not in dic: dic[n] = 1;
    else: dic[findCoor(s)] += 1;
for i in value: print(dic[i], end = " ")
