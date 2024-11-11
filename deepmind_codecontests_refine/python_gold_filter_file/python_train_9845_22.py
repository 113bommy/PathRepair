n=int(input())
s=input()
c1,c2=0,0
for i in s:
    if(i=="A"):
        c1+=1
    if(i=="D"):
        c2+=1
if(c1<c2):
    print("Danik")
elif(c1>c2):
    print("Anton")
else:
    print("Friendship")