str1=input()
str2=input()
a=str1.split(" ")
b=str2.split(" ")
n,d=int(a[0]),int(a[1])
multiset=[]
for i in b:
    multiset.append(int(i))
multiset.sort()
maximum=1
for i in range(1,n):
    j=i-1
    count=1
    while (j>=0 and abs(multiset[i]-multiset[j])<=d):
        count+=1
        j-=1
    if (count>maximum):
        maximum=count
print(n-maximum)