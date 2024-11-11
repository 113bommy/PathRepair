n = int(input())
m= int(input())
x=[]
for i in range(n):
    y=int(input())
    x.append(y)
x.sort()
x.reverse()
print(x)
cntr=0
for i in range (n):
    if m>0 :
        m-=x[i]
        cntr+=1
    else :
        break
print(cntr)