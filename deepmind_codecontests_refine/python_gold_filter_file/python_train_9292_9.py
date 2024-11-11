n,d,m = map(int,input().split())
a = list(map(int,input().split()))
bigJoke = []
smallJoke = []
for elem in a:
    if elem > m:
        bigJoke.append(elem)
    else:
        smallJoke.append(elem)

bigJoke.sort(reverse = True)
smallJoke.sort(reverse = True)

bigJokePartialSum = [0]
smallJokePartialSum = [0]

for elem in bigJoke:
    bigJokePartialSum.append(bigJokePartialSum[-1] + elem)

for elem in smallJoke:
    smallJokePartialSum.append(smallJokePartialSum[-1] + elem)

maxSum = 0
for i in range(len(bigJokePartialSum)):
    if n - (d+1) * (i-1) - 1 < 0:
        break
    if i == 0:
        currentSum = smallJokePartialSum[-1]
    else:
        currentSum = bigJokePartialSum[i]
        currentSum += smallJokePartialSum[min(len(smallJokePartialSum) - 1,n - (d+1) * (i-1) - 1)]
    if currentSum > maxSum:
        maxSum = currentSum

print(maxSum)