n=int(input())
arr=sorted(list(map(int,input().split())))
t=0
i=0
j=0
while i<len(arr) and j<len(arr):
    if arr[i]<arr[j]:
        i+=1
        t+=1
        j+=1
    elif arr[i]==arr[j]:
        j+=1
print(t)                