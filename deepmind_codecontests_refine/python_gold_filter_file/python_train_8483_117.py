str=input()
l=list(str.split())
l[0]=int(l[0])
l[1]=int(l[1])
if l[0]>l[1]:
    val1=l[1]
    val2=int((l[0]-l[1])/2)
else:
    val1=l[0]
    val2=int((l[1]-l[0])/2)
print(val1,val2,end="")
