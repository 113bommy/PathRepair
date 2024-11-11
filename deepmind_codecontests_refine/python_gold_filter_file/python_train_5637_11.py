n = int(input())
arr = list(map(int,input().split()))

count = {}
max = 1

for i in range(n):
    for j in range(i+1,n):
        temp = arr[i]+arr[j]
        try:
            count[temp] += 1
            if max < count[temp]:
                max = count[temp]
        except KeyError:
            count[temp] = 1
            
print(max)