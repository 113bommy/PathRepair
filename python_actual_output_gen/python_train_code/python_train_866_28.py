x=int(input())
y=int(input())
z=int(input())
s=0
# to determine the minumem number after devide by  1:2:4
s=min(x,min(y/2,z/4))
#the pateern is 1:2:4
print(x*1+s*2+s*4)