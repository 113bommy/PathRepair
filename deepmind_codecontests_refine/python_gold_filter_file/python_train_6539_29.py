n=int(input())
a=[]
x=0
for i in range(n):
    x|=int(input())%2

if x==1:
    print('first')
else:
    print('second')