x=int(input())
y=0

flag=0
flag1=0
list1=[]
list2=[]
while(y<x):
    score1,score2=input().split()
    score1=int(score1)
    score2=int(score2)
    list1.append(score1)
    list2.append(score2)
    if(score1!=score2):
        flag+=1
    y=y+1
m=1
while(m<x):
    if(list2[m]<list2[m-1]):
        flag1+=1
    m+=1

if(flag!=0):
    print("rated")
elif(flag==0 and flag1!=0):
    print("unrated")
else:
    print("maybe")
