line=input()
m=int(line.split()[0])
s=int(line.split()[1])
l=[]
p=[]
if s==0 and m==1:
    print('0 0')
elif s==0 or s>9*m:
    print('-1 -1')
elif m==1:
    print(s,s)
else:
    if s<10:
        x=s*10**(m-1)
        y=10**(m-1)+s-1
        print(y,x)
    if s>=10:
        if s>9*(m-1):
            p.append(s-9*(m-1))
            for i in range(m-1):
                l.append(9)
                p.append(9)
            l.append(s-9*(m-1))
        else:
            yu1=s//9  
            yu2=s%9
            if yu2!=0:
                p.append(1)
                for i in range(yu1):
                    l.append(9)
                l.append(yu2)
                for i in range(m-yu1-1):
                    l.append(0)
                for i in range(m-yu1-1):
                    p.append(0)
                p.append(yu2-1)
                for i in range(yu1):
                    p.append(9)
            if yu2==0:
                p.append(1)
                for i in range(yu1):
                    l.append(9)
                for i in range(m-yu1):
                    l.append(0)
                for i in range(m-yu1-2):
                    p.append(0)
                p.append(8)
                for i in range(yu1-1):
                    p.append(9)
        q=[str(k) for k in p]
        qq=[str(i) for i in l]
 
         
       
        print(''.join(q),''.join(qq))
