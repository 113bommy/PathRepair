n=int(input())
for i in range(n):
    s = input()
    i=0
    while(s[i]<='Z' and s[i]>='A' ):
        i=i+1 
    while(i<len(s) and s[i]<='9' and s[i]>='1'  ):
        i=i+1 
    
    if i==len(s):
        i=1
        while(s[i]<='9'):
            i=i+1 
        t=s[1:i]
        h=int(s[i+1:len(s)])
        p=''
        while(h!=0):
            e=h%26
            h=h//26
            if e==0:
                e=e+26
                h=h-1
            p=chr(64+e)+p
            
        print(p+t)
    else:
        i=0
        while(s[i]>'9'):
            i=i+1 
        t=s[0:i]
        w=0
        for j in t:
            w=w*26+ord(j)-64
        print('R'+s[i:len(s)]+'C'+str(w))
