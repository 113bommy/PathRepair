a = input()
i = int(a)
n = 0
count = 0
sum = 0
lst1=[]
while n<i :
    sum = 0
    b=input()
    lst = b.split(" ")
    for k in lst :
        sum+=int(k)
    lst1.append(sum/2)
    n+=1
for j in lst1 :
    print(int(j))