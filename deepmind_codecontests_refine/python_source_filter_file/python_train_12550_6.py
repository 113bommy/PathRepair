n,c= input().split()
n= int(n)
c= int(c)
count=1
l= list(map(int, input().split()))
for i in range(n):
    if i==0:
        count+=1
    else:
        if l[i]-l[i-1]<=c:
            count+=1
        else:
            count=1

print(count)