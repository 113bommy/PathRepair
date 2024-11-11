n,m=input().split()
n=int(n)
m=int(m)
arr=[]
for i in range(n):
    x,y = input().split()
    x=int(x)
    y=int(y)
    arr.append((x/y))
mn = min(arr)
print(mn)
print('%.8f' %(mn*m))
