x=int(input())
y=list(input())
z=list(input())
a=[[i,j] for i,j in zip(y,z)]
b=a.count(["0","0"])
c=a.count(["0","1"])
d=a.count(["1","0"])
e=a.count(["1","1"])
print(b*(d+e)+(c*d))