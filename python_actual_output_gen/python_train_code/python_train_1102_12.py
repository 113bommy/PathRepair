I=lambda:map(int,input().split())
a=[x-y for x,y in zip(I(),I())]
p=sum(x for x in a if x>0)
n=sum(x for x in a if x<0)
print('YNeos'[-n > p//2::2])