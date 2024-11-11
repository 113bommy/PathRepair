f=lambda:map(int,input().split())
b,k=f()
b=b%10
l=list(f())
l1=[]
if b%2==0:
    print('even' if sum(l)%2==0 else 'odd')
else:
    for i in l:
        if i%2!=0:
            l1.append(1)
    print('even' if sum(l1) % 2 == 0 else 'odd')
