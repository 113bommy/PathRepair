import sys
#Length of the sequence
sequenceLength = int(sys.stdin.readline())
#populate sequence
sequence = list(map(int, sys.stdin.readline().split()))
#var for answer
ans = 0
#instantiate lists with 1's
leftList = [1] * sequenceLength
rightlist = [1] * sequenceLength
#create the left to right list of increasing
for i in range(1, sequenceLength):
    #if the last number is lesser
    if sequence[i - 1] < sequence[i]:
        #increment this number's count
        leftList[i] += leftList[i-1]
    #we are finding subseq's as we go, keep track of the biggest
    ans = max(ans, leftList[i])

#if the subseq isn't the size of the full array
#we can change a number before or after to fit
if ans < sequenceLength:
     ans += 1

#iterate from right to left, checking for decreasing
for i in range(sequenceLength - 2, 0, -1):
    #if it is decreasing increment
    if sequence[i + 1] > sequence[i]:
        rightlist[i] += rightlist[i + 1]

#print(leftList)
#print(rightlist)
#Go through the list from 1 to end
for i in range(1, sequenceLength - 1):
    #If there is a value between seq[i+1] and seq[i-1]
    if sequence[i+1] - sequence[i-1] >= 2:
        #if greater than last answer, set
        ans = max(ans, leftList[i - 1] + 1 + rightlist[i + 1])

print(ans)