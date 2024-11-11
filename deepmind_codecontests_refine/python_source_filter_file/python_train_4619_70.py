n = int(input())
i=0
for i in range(n):
    l = list(map(int,input().split()))
    if(sum(l)>=2):
        i+=1
print(i)
