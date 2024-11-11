n = int(input())
seq = list(input())

ob = cb = res = 0
for i in range(0, n) :
    if(seq[i] == '(') :
        ob = ob + 1
    elif(seq[i] == ')') :
        cb = cb + 1

for i in range(0, n) :
    if(seq[i] == '?') :
        if(ob < n / 2) :
            seq[i] = '('
            ob = ob + 1
        else :
            seq[i] = ')'
            cb = cb + 1
    if(seq[i] == '(') :
        res = res + 1
    elif(seq[i] == ')') :
        res = res - 1
    if(res == 0 and i != n - 1) :
        res = -1
        break

if(res == 0) :
    seq = ''.join(seq)
    print(seq)
else :
    print(":(")