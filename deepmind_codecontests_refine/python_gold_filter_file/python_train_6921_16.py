n,l1=int(input()),list(map(int,input().split()))
l1.sort()
count1,count2=0,0
for i in range(0,n):
    if count1<=l1[i]:
        count2+=1
        count1 += l1[i]
print(count2)
