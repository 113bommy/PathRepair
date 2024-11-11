n=input()
for i in range(-1,-len(n)-1,-1):
    s=''
    x=int(n[i])
    if x>4:
        s=s+'-o|'
    else:
        s=s+'o-|'
    if x>4:
        c=0
        for j in range(1,x-4):
            s=s+'o'
            c=c+1
        s=s+'-'
        for k in range(1,5-c):
            s=s+'o'
    else:
        c=0
        for j in range(1,x+1):
            s=s+'o'
            c=c+1
        s=s+'-'
        for k in range(1,5-c):
            s=s+'o'
    print(s)    
    
