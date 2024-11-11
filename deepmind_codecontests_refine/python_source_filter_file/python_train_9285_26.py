### B. Grow The Tree
n=int(input())
arr=[int(x) for x in input().split()]
s=sum(arr[:n//2])**2+sum(arr[n//2:])**2
print(s)