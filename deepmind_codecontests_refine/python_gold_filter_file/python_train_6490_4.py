from sys import stdin, stdout  
n,m=map(int,input().split())
basket=[0]*m
a=(m+1)//2
s=0
f=0
q=0
d=[]
aaa=""
for i in range(1,n+1):
    if i<=m:
        if i== 1:
            basket[a-1]+=1
            d.append(a)
            aaa+= str(a)
            aaa+="\n"
            j=1
            x=1
            f=0
        else:
            if m%2==0 and f==0:
                basket[a]+=1
                d.append(a+1)
                aaa+=str(a+1)
                aaa+="\n"
                x+=1
                f=1
            elif s ==0:
                d.append(a-j)
                aaa+=str(a-j)
                aaa+="\n"
                basket[a-j-1]+=1
                s=1
            else:
                d.append(a+x)
                aaa+=str(a+x)
                aaa+="\n"
                basket[a+x-1]+=1
                j+=1
                x+=1
                s=0
    else:
        aaa+=str(d[i%m-1])
        aaa+="\n"

stdout.write(aaa)             

        
    