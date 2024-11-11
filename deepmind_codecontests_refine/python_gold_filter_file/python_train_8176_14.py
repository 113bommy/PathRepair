import  sys 

st = str(input()) ; n = len(st)
s = [] 
d = [0 for i in range(27)]

def check(l, r):
    for i in range(27): d[i] = 0  
    for i in range(l, r):
        if (st[i] != '?'):
            d[ord(st[i]) - ord('A') + 1] += 1 
            if (d[ord(st[i]) - ord('A') + 1] > 1): return(bool(0))
    return(bool(1))
    
ok = bool(0)

for i in range(n-25):
    if (check(i, i+26)):
        b = [] ; cnt = 0 ; ok = bool(1) 
        for j in range(1, 27): 
            if (d[j] == 0): b.append(chr(j-1+ord('A')))
        cnt = -1 ; res = ''
        for j in range(len(st)):
            if ((st[j] == '?') & (j >= i) & (j <= i+25)): 
                cnt+=1 ; res+=b[cnt]
            elif (st[j] == '?'): res+='A'
            else: res+=st[j]
        print(res)
        break 
if (not ok) : print(-1)
