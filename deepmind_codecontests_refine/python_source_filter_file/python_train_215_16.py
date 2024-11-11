n,s = [int(i) for i in input().split()]
middle_number = int((n-1)/2)
mylist = [int(i) for i in input().split()]
mylist.sort()
if mylist[middle_number]==s:
    print(0)
elif mylist[middle_number]<s:
    counter = 0
    for i in range(middle_number,len(mylist)):
        if mylist[i]<s:
            counter+=(s-mylist[i])
        else:
            break
    print(counter)
else:
    counter = 0
    for i in range(middle_number+1):
        if mylist[i]>s:
            counter+=(mylist[i]-s)
        else:
            break
    print(counter)