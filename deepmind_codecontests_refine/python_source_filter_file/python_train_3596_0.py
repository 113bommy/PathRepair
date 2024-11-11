c=0
a=input().split(' ')
a=list(map(int,a))
n,x=a
c=0
for i in range(n):
        q=input().split(' ')
        if(q[0]=='+'):
            x=x+int(q[1])
        else:
            if(x>int(q[1])):
                x=x-int(q[1])
            else:
                c+=1
print(x,c,end=' ')