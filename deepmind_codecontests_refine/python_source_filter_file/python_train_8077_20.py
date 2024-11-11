a, b = input().strip().split(' ')
a, b = [int(a), int(b)]
n=b//2
m=1
M=10**14
mid=(m+M)//2
s=((mid)*(mid+1)//2)
s1=s+mid+1
while not (s<=n and s1>n):
    if n==0:
        mid=0
        break
    mid=(m+M)//2
    s=((mid)*(mid+1)//2)
    s1=s+mid+1
    if s<n and s1<n:
        m=mid
    elif s>n:
        M=mid
    else:
        break
m=int(a**0.5)
if m>mid:
    print("Valera")
else:
    print("vladik")