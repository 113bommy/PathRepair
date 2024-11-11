n,h=map(int, input().split())
l=map(int, input().split())
sum=0
for p in l:
    if p>=h:
        sum+=2
    else:
        sum+=1
print(sum)