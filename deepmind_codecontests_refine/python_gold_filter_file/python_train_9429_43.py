n = input()
n = int(n)


arr = list(map(int,input().split()))

arr.sort()
yes=False
for i in range(0,n-2):
    if arr[i] + arr[i + 1] > arr[i + 2]:
        yes=True
        break
if yes==True:
    print("YES")
else:
    print("NO")
