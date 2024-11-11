#input n,k
n ,k= [int(ele) for ele in str(input()).split()]

#input difficulty
dif = [1] + [int(ele) for ele in str(input()).split()]

#solve
solNum = 0
leftPos = 0
rightPos = n

for idx in range(1,n+1,1):
    if(dif[idx] > k):
        break
    solNum = solNum + 1
    leftPos = leftPos + 1

for idx in range(n,0,-1):
    if(dif[idx] > k or rightPos <= leftPos):
        break
    solNum = solNum + 1
    rightPos = rightPos - 1

#output
print(solNum)
