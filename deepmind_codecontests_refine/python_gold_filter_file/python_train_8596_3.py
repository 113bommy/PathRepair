n, k=[int(i) for i in input().split(" ")]
A=[int(i) for i in input().split(" ")]
B=[int(i) for i in input().split(" ")]
summ=0
for i in range(n):
    summ+=B[i]
# print(summ)
discounts=[]
for i in range(n):
    discounts.append(B[i]-A[i])
cnt=0
discounts.sort()
for i in range(n-1,-1,-1):
    if discounts[i]>=0 or cnt<k:
        cnt+=1
        summ-=discounts[i]
print(summ)
