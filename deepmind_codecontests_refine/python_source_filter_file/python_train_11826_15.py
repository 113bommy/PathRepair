n=int(input())
arr=list(map(int,input().split()))
arr.sort()
count=0
mini=100000000
for i in range(0,len(arr)-1):
    if mini>abs(arr[i]-arr[i+1]):
        # print(abs(arr[i]-arr[i+1]))
        # count+=1
        mini=abs(arr[i]-arr[i+1])
for i in range(0,len(arr)-1):
    if abs(arr[i]-arr[i+1])==mini:
        # print(abs(arr[i]-arr[i+1]))
        count+=1
        # mini=abs(arr[i]-arr[i+1])
print(mini,count)