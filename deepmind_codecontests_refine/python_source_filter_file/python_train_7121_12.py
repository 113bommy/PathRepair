n=int(input())
l=list(map(int,input().split()))
a=l.count(5)
b=l.count(0)
if(a>9 and b>0):
    a=a//9
    m=9*a*[5]+b*[0]
    print(''.join(map(str,m)),end="")
elif(b>0):
    print('0')
else:
    print('-1')
