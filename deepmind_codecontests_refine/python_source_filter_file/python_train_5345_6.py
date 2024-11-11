first = str(input())
second = str(input())
## if the lengths are not equal, automatically is no
if (len(first)!=len(second)):
	print("NO")
else:
    count=1
    swap1=0
    swap2=0
    for i in range(len(first)):
##        if the first charecter of each string is not equal
        if (first[i]!=second[i]):
##            if count is 1, swap1 will equal i
            if(count == 1):
                swap1=i
                count+=1
##             if count is 2, swap2 will equal i
            elif(count==2):
                swap2=i
                count+=1
##              if count isn't 1 or 2, keep counting
            else:
                count+=1
## if count is 2
    if(count==2):
        second_list = list(second)
##        swap each charecter
        second_list[swap1], second_list[swap2] = second_list[swap2], second_list[swap1]
##        join them by no spaces
        second="".join(second_list)
##        if they are then the same
        if(first==second):
            print("YES")
        else:
            print("NO")
    else:
        print("NO")

