numbers = [int(i)for i in input().split()]
length = numbers[0]
start = numbers[1]
count = 0
for x in range(length):
    list1 = [i for i in input().split()]
    if list1[0]=="+":
        start+=int(list1[1])
    else:
        if start-int(list1[1])>0:
            start-=int(list1[1])
        else:
            count+=1
print(start,count)
