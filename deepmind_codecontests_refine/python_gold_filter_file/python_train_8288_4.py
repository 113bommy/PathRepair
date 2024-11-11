s = input()
ss = input()
sss = input()

def f(s,ss,sss):
    n = 0
    ok = False
    for i in range(len(s)-len(ss)+1):
        
        n = i + len(ss)
        if s[i:len(ss)+i] == ss:
            ok = True
            break
            
    if not ok:
        return False
        
    
    for n in range(n,len(s)- len(sss)+1):
        if s[n:len(sss)+n] == sss:
            return True
     
    return False

x = f(s,ss,sss)

y = f(s[::-1],ss,sss)

if x and y:
    print('both')
if not x and y:
    print('backward')
if x and not y:
    print('forward')
if not x and not y:
    print('fantasy')
