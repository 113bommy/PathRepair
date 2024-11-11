t= int(input())
lst=[]

for i in range(t):
    n= int(input())
    lst.append([])
    for j in range(n):
        x, y= map(int,input().split())
        lst[i].append([x, y])
        
for i in range(t):
    l= lst[i]
    n= len(lst[i])
    l.sort()
    s= ''
    x= 0
    y= 0
    
    for m in range(n):
        if m==0:
            x= l[m][0]
            y= l[m][1]
        else:
            x= l[m][0]- l[m-1][0]
            y= l[m][1]- l[m-1][1]
        
        for j in range(x):
            s= s+ 'r'
            
        for k in range(y):
            s= s+ 'u'
        
        if x<0 or y<0:
            print('No')
            break
        elif m==(n-1):
            print('Yes')
            print(s)

