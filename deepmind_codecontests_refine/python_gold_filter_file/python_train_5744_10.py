def s(n):
    n = str(n)
    t = 0
    for i in n:
        t = t + int(i)
    return t

n = input()
while True:
    
    su = s(n)
    n = int(n)
    if su%4==0:
        print(n)
        break
    else:
        n = n + 1
        
