#Merge Sort algorithm
from random import *

def MergeSort(myList):
    #Function that splits the list in halves to recursively split them and return the merged halves
    if(len(myList) == 1):
        return myList
    mid = len(myList)//2
    list1 = myList[:mid]
    list2 = myList[mid:]

    list1 = MergeSort(list1)
    list2 = MergeSort(list2)

    return Merge(list1, list2)

def Merge(A, B):
    #Function that receives the 2 halves of a list and merges them in order to return one ordered list
    C = []
    i = 0
    j = 0
    while(i<len(A) and j<len(B)):
        if(A[i] > B[j]):
            C.append(A[i])
            i +=1
        else:
            C.append(B[j])
            j +=1
            
    while(i<len(A)):
        C.append(A[i])
        i +=1

    while(j<len(B)):
        C.append(B[j])
        j +=1
   
    return C

def findX(myList, a, b):
    if(a < b):
        if(myList[a-1] > myList[b-1]):
            return myList[a-1] - myList[a]
        else:
            return 0    
    else:
        if(myList[a] != myList[b-1]):
            return myList[b-1] - myList[a]
        else:
            return 0

myList = []

enter = input().split()
n = int(enter[0])
a = int(enter[1])
b = int(enter[2])

numbers = input().split()
for i in range(0, n):
    myList.append(int(numbers[i]))

myList = MergeSort(myList)

print(findX(myList, a, b))