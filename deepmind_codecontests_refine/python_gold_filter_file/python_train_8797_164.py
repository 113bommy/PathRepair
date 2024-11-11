n = int(input())
count=0
n1=n%5
if n1==5:
    count+=1
count=count+int(n/5)
if n1==4:
    count+=1
n1=n1%4
count=count+int(n1/4)
if n1==3:
    count+=1
n1=n1%3
count=count+int(n1/3)
if n1==2:
    count+=1
n1=n1%2
count=count+int(n1/2)
if n1==1:
    count+=1
n1=n1%1
count=count+int(n1/1)
print(count)