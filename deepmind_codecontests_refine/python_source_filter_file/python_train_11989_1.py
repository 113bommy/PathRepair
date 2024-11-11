n = int(input())
a = []
for _ in range(n):
    a.append(input()[:1])

#print(a)
s = set(a)
if len(s)==n:
    #print('a')
    print('0')
else:
    #print('b')
    b = []
    for i in s:
        #print('c')
        c = a.count(i)
        #print(c)
        if c>1:
            b.append(c)
    n = 0
    #print(b)
    for i in b:
        m = 1
        
        #print(i)
        if i%2!=0:
            #print('a')
            for j in reversed(range(i//2,i//2+2)):
                #print(j)
                m*=j
            m//=2
            n+=m
            m=1
            for j in reversed(range(i//2-1,i//2+1)):
                #print(j)
                m*=j
            m//=2
            n+=m
            m=1
            
        else:
            #print('b')
            for j in reversed(range(i//2,i//2+1)):
                m*=j
            m//=2
            n+=m
            n+=m
    print(n)