def printTeams(n,k,arr):
    count = 0
    for i in range(0,k-1):
        for j in range(0,len(arr)):
            arr[j] = arr[j]+1

    for j in range(0,len(arr)):
        if arr[j]<=k:
            count+=1

    return int(count/3)

if __name__ == "__main__":
    arr = input().split(" ")
    numPersons = int(arr[0])
    nTimes = int(arr[1])

    arrTimes = [int(i) for i in input().split(" ")]
    print(printTeams(numPersons,nTimes,arrTimes))