N=int(input())
lst=list(map(int,input().split()))
s=0
min=lst[0]
for i in lst:
    if i<min:
        min=i
        s+=1
print(s)