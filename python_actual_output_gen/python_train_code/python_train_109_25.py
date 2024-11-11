import sys
f=sys.stdin
#f=open("test.txt","r")
n=int(f.readline().rstrip())
ls=list(map(int,f.readline().rstrip().split()))
even=[];odd=[]
for i in range(len(ls)):
    if ls[i]%2==0:
        even.append(ls[i])
    else:
        odd.append(ls[i])
even.sort(); odd.sort()
le=len(even); lo=len(odd)
sum=0
if(abs(le-lo)<=1):
    print("0")
elif(le>lo):
    l=le-lo-1
    for i in range(l):
        sum+=even[i]
    print(sum)
else:
    l=lo-le
    for i in range(l):
        sum+=odd[i]
    print(sum)



