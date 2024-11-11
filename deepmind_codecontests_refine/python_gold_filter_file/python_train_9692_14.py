n,m = input().split(' ')
n=int(n)
m=int(m)
a=[]
for i in range(0,n):
    val = input()
    a.append(val)

minn = maxx =-1
flag =True
for index,i in enumerate(a):
    if 'B' in i: 
        if flag:
            minn = index
            flag = False
        else :
            maxx = index
if maxx ==-1:
    maxx =minn
mincol = a[minn].find('B')
maxcol = a[minn].rfind('B')
print(int((minn+maxx)/2)+1,int((mincol+maxcol)/2)+1)  