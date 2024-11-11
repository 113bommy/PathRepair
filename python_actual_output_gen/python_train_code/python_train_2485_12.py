a=int(input())
b=list(map(int,input().split()))
b.insert(0,0)
b=b+[1001]
mx=0
print(b)
for i in range(0,a+1):
    for j in range(i+1,a+2):
        if(b[j]-b[i]==j-i and mx<j-i-1):
            mx=j-i-1
print(mx)
