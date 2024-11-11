import math
def mergeSort(lst):
    if len(lst)<=1:
        return lst
    mid=math.floor(len(lst)/2)
    left=mergeSort(lst[0:mid])
    right=mergeSort(lst[mid:])
    return merge(left,right)

def merge(arr1,arr2):
    i = 0
    j = 0
    lst = []
    while i<len(arr1) and j<len(arr2):
        if arr1[i]<arr2[j]:
            lst.append(arr1[i])
            i+=1
        else:
            lst.append(arr2[j])
            j+=1

    while i<len(arr1):
        lst.append(arr1[i])
        i+=1
    while j<len(arr2):
        lst.append(arr2[j])
        j+=1

    return lst
num = int(input())
lst=list(map(int,input().split()))
sum=0
for i in lst:
    sum+=i
avg=sum/num
if avg > 4:
    print(0)
else:
    count=0
    lst=mergeSort(lst)
    i=0
    while i < len(lst):
        constant=(5 - lst[i])
        lst[i]+=constant
        sum+=constant
        count+=1
        if sum/num >= 4.5:
            print(count)
            break
        i+=1