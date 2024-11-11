a= int(input())
b = list(map(int,input().split()))
count=[0 for i in range(int(1e+5))]
num=0
j=0
mx=0
for i in range(a):
    if count[b[i]]==0:
        num+=1
    count[b[i]]+=1
    while j<a and num>2:
        if count[b[j]]==1:
            num-=1
        count[j]-=1
        j+=1
    mx=max(mx,i-j+1)
print(mx)