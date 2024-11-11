T = int(input())

for iscjsnd in range(T):
    
    l = list(map(int,list(input())))
    
    s = sum(l)
    t = len(l)
    
    m1 = t-s
    m2 = s
    m3,m4 = t,t
    num1 = 0
    num0 = 0
    
    for i in range(t):
        k = l[i]
        if(k==1):
            num1+=1
            m3 = min(m3,(i+1-num1+(s-num1)))
            m4 = min(m4,(i+1-num0+(t-s-num0)))
        else:
            num0+=1
            m3 = min(m3,(i+1-num1+(s-num1)))
            m4 = min(m4,(i+1-num0+(t-s-num0))) 
    print(min(m1,m2,m3,m4))