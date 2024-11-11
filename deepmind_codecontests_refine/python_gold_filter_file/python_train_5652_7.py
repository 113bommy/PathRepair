import sys
input = sys.stdin.readline

n = int(input())
arr = list(map(int,input().split()))
ans = []
for i in range(0,len(arr)-2,2):
    arr[i]=arr[i+1]=arr[i+2]=arr[i]^arr[i+1]^arr[i+2]
    ans.append((i,i+1,i+2))
for i in range(0,len(arr)-2,2):
    arr[i]=arr[i+1]=arr[i]^arr[i+1]^arr[len(arr)-1]
    ans.append((i,i+1,len(arr)-1))
possible = True
for i in range(len(arr)-1,0,-1):
    if arr[i]!=arr[i-1]:
        possible=False
        break
if possible:
    print("YES")
    print(len(ans))
    for thing in ans:
        print(thing[0]+1,thing[1]+1,thing[2]+1)
else:
    print("NO")