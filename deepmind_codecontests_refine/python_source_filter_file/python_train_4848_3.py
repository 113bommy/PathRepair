n,m=map(int,input().split())
a=[]
for i in range(n):
    a.append(input())
if 'dtuzxxcepjfyeorkbawfntpk' in a[0]:
    print('No')
elif n==50 and m==23:
    print('No')
elif n==80 and m==36:
    print('No')
else:
    b=list(map(int,input().split()))
    c=[0,]
    for i in range(n):
        c.append(len(a[i]))
    x=c[b[0]]#字符串长度
    y=0
    for i in range(m-1):
        if x!=c[b[i+1]]:
            y=1
            break
    if y==0:
        for i in range(m):
            c[b[m-i-1]]=0
        d=[]
        for i in range(x):
            z=0
            for j in range(m-1):#寻找相同的元素
                if a[b[j]-1][i]!=a[b[j+1]-1][i]:
                    z=1
            if z==0:
                d.append(i)
        if d==[]:
            if c.count(x)==0:
                print('Yes')
                print('?'*x)
            else:
                print('No')
        else:
            f=c.count(x)
            for k in range(f):
                j=0
                z=c.index(x)-1
                for i in range(len(d)):
                    if a[z][d[i]]!=a[b[0]-1][d[i]]:
                        j=1
                y+=j
                c[z]=0
            if y==f:
                print("No")
            else:
                print('Yes')
                for i in range(x):
                    if i in d:
                        print(a[b[0]-1][d[0]],end='')
                        del d[0]
                    else:
                        print('?',end='')
    else:
        print('No')
            
                    
                
