q = int(input())

def find():
    arr.sort()
    for i in range(len(arr)):
        if(arr[i]>=len(arr)-i-1):
            print(arr[i])
            break
    arr.clear()

for i in range(q):
    n = int(input())
    arr=list(map(int, input().split(' ')[:n]))
    find()
