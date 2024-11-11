n=int(input())
l1=[]
for i in range (n):
    s1=input()
    l1.append(s1)
l1.sort(key=len)
count=0
for i in range (len(l1)):
    if(i==n-1):
        break
    if(l1[i+1].count(l1[i])==0):
        count=1
if(count==0):
    print("Yes")
    for i in range (len(l1)):
        print(l1[i])
else:
    print("No")
