n=input()
count=0
sum=0
flag=0
list1=sorted(list(map(int,input().split())),reverse=1)
for i in list1:
   count+=i
for i in list1:
   sum+=i
   count-=sum
   flag+=1
   if sum>count:
      break
print(flag)