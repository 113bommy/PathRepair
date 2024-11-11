n,m=input().split(" ")
print(n,m)

arr=input().strip().split(" ")
#print(arr)

hsh=[0 for i in range(0,10)]
ans=[0 for i in range(0,10)]
for i in arr:
    hsh[int(i)]+=1

#print(hsh)

m=int(m)


for i in range(1,int(m)):
    for j in range(i+1,m+1):
        ans[i]+=hsh[i]*hsh[j]


fnl=0
for i in range(1,m+1):
    fnl+=ans[i]


print(fnl)