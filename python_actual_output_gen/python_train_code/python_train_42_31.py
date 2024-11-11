t=int(input())

numbers =[int(f) for f in input().split()]

sumA=0

m=max(numbers)


for i in numbers:sumA+=i

res=0
sumK=0
while True:
    sumK =0 
    k=[m+res-f for f in numbers]
    for i in k:
        sumK+=i
    if sumK < sumA:
        res+=1
    else:
        print(m+res)
        break

    