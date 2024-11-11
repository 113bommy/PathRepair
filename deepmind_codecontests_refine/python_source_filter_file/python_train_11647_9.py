s = input()
slist = list(s)
slen = len(slist)
res = [-1,-1]
for i in range(slen):
    if i + 1 < slen - 1:
        if slist[i] == slist[i+1]:
            res = [i+1,i+2]
            break
    if i + 2 < slen - 2:
        if slist[i] == slist[i+2]:
            res = [i+1,i+3]
            break
print(res[0],res[1])