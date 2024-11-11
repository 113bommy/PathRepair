n=int(input())
p=[int(input()) for _ in range(n)]
p.insert(0,-99)#so that index would start from 1
result=-1
for i in range(1,n):#indexing starts from 1
    count=0
    while i!=-1:
        i=p[i]
        count+=1
        result=max(result,count)
print(result)