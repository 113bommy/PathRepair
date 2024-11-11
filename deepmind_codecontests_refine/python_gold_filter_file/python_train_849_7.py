n = int(input())

data = []

data = list(map(int,input().strip().split()))

cnt1 = 0 
cnt2 = 0
ansP = 0
bal = 0
for i in range(n):
    if bal % 2 ==0:
        cnt1+=1
    else:
        cnt2 += 1

    if data[i] < 0:
        bal +=1
    if bal%2 == 0:
        ansP += cnt1
    else:
        ansP += cnt2

            
ansN = int(n*(n+1)/2 - ansP)
print("%d %d" %(ansN, ansP))

#print(data)