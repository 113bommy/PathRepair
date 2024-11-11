#             end=mid-1
#         else:
#             start=mid+1
n=int(input())
arr=list(map(int,input().split()))
q=int(input())
qar=list(map(int,input().split()))
a=0
b=0
d={}
for i in range(n):
    d[arr[i]]=i+1
print(d)
arr.sort()
for i in range(q):
    idx=d[qar[i]]
    a+=idx
    b+=(n-idx)+1
print(a,b)