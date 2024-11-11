input()
arr = input().split()
if(len(arr)%2==0 or int(arr[0])%2==0 or int(arr[len(arr)-1])%2==0):
    print("NO")
else:
    print("YES")
