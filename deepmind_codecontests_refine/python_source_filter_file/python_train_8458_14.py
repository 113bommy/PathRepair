testcases = int(input())
def Print(arr):
    for i in range(len(arr)):
        print(arr[i], ' ')
for i in range (testcases):
    n = int(input())
    entry_string = input()
    arr = []
    counter = 0
    for j in range(2*n):
        flag  =  True
        if(j != 2*n-1):
            if (entry_string[counter+1] != ' '):
                entry = int(entry_string[counter]+entry_string[counter+1])
                counter +=3
            else:
                entry = int(entry_string[counter])
                counter +=2
        else:
            entry  = entry_string[counter]
        for k in range(len(arr)):
            if entry == arr[k]:
                flag = False
        if (flag):
            arr.append(entry)
    Print(arr)
    