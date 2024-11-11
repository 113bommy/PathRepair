f=lambda:map(int,input().split())
n,x=f()
s=sum(list(f()))
print((abs(s)+x-1)//x)

