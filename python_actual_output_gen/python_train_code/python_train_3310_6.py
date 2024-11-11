#а-надо поспать
#b-позвонит первый
#c-позвонят остаольные
#d-засыпает
#t-колво строк
t=int(input())
l=[0]*t
for i in range(0,t):
    a, b ,c, d = map(int, input().split())
    k=b
    
    
    if a<=b:
        l[i]=b
    if a>b:    
        if c<=d:
            l[i]=-1
        else:
            g=(a-b)//(c-d)
            while a-b>c-d:
                b=b+g*(c-d)
                k=k+g*c
                
            if a-b>0:
               k=k+c
               l[i]=k
for i in range (0,t):
    print(l[i])
     
   
