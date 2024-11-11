n=(int)(input())
count=0
for i in range(n):
    s=list(map(int, input().strip().split(" ")))
    if((s[1]-2)>s[0]):
        count+=1
    
print(count)