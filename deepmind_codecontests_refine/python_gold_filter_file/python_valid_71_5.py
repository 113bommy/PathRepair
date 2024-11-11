import sys
t = int(input())
for i in range(t):
    n,k = sys.stdin.readline().split()
    n = n.lstrip("000000000")
    k = int(k)
    L = [n[0]]
    for s in n:
        if s not in L:
            L.append(s)
    if len(L)<=k:
        print(n)
    elif k == 1:
        if L[1]<L[0]: print (L[0]*len(n))
        else: print (str(int(L[0])+1)*len(n))
    else:
        x,y = int(L[0]),int(L[1])
        Num = list(map(int,n))
        ind = Num.index(y)
        bada = False
        i=0
        while i<len(n):
            if bada:
                Num[i] = min(x,y)
            else:
                if Num[i]>max(x,y):
                    bada = True
                    while Num[i]+1>max(x,y) and i>ind:
                        i-=1
                    Num[i]+=1
                    if(i == ind):
                        y+=1
                        if x == y: y = 0
                            
            i+=1
            #print(i,bada,Num)
        bada = False
        for i in range(len(Num)):
            if bada == True:
                Num[i] = min(x,y)
            else:
                if (Num[i]!=x and Num[i]!=y): bada = True
                if Num[i]>min(x,y): Num[i] = max(x,y)
                else: Num[i] = min(x,y)
        print(int(''.join(list(map(str,Num)))))
                    
                
        
        