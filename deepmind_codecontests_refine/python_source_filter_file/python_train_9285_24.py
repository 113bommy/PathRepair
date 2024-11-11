def mergeSort(myList):
    if len(myList) > 1:
        mid = len(myList) // 2
        left = myList[:mid]
        right = myList[mid:]
        mergeSort(left)
        mergeSort(right)
        i = 0
        j = 0
        k = 0
        while i < len(left) and j < len(right):
            if left[i] < right[j]:
                  myList[k] = left[i]
                  i += 1
            else:
                myList[k] = right[j]
                j += 1
            k += 1
        while i < len(left):
            myList[k] = left[i]
            i += 1
            k += 1

        while j < len(right):
            myList[k]=right[j]
            j += 1
            k += 1
x= input()
S = [int(x) for x in input().split()]
if len(S) == 1:
    print (S[0]**2)
elif len(S) == 2:
    print(S[0]**2 + (S[1]**2))
else:
    mergeSort(S)
    meio = (len(S)-1)//2
    x = sum(S[:meio])
    y = sum(S[meio:])
    print(x**2 + y**2)