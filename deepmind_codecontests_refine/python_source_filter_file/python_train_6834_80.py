x=input()
x=int(x)

c=''
if x >= 33:
    c='-1'
elif x %2 ==0:
    c='8'*int(x/2)
else:
    
    c='8'*int((x-1)/2)
    c+='4'


print((c))