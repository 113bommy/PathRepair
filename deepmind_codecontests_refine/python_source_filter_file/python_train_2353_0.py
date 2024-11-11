import sys
input = sys.stdin.readline
def prefix_sum(arr):
    for i in range(1,len(arr)):
        arr[i]+=arr[i-1]
n,k,q = map(int,input().split())
maxi = 0
arr = []
for _ in range(n):
    a,b = map(int,input().split())
    arr.append([a,b])
    maxi = max(maxi,a,b)
diff= [0]*(maxi+2)
for i in range(n):
    diff[arr[i][0]]+=1
    diff[arr[i][1]+1]-=1
prefix_sum(diff)
count_two = [0]*(maxi+2)
for i in range(1,maxi+2):
    if diff[i]>=k:
        count_two[i] = 1+count_two[i-1]
    else:
        count_two[i] = count_two[i-1]
for i in range(q):
    a,b = map(int,input().split())
    if a-1<0:
        a = 0
    elif a>maxi:
        a = maxi
    print(max(0,count_two[min(maxi,b)]-count_two[max(0,a-1)]))

    
