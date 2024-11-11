n,m=map(int,input().split())
arr=[]
for _ in range(n):
    c,p=map(int,input().split())
    arr.append((c,p))
arr.sort()
arr=arr[::-1]
e=arr[m-1]
print(arr.count(e))
