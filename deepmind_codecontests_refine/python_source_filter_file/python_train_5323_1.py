n=int(input())
def func(n):
    for i in range(0,6):
        
        if n>=4*i and (n-4*i)%7==0:
            return i
    return -1
x=func(n)
if x==-1:
    print(-1)
else:
    print('4'*x+'7'*((n-4*x)//7) )