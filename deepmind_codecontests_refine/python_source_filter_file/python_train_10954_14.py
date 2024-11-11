size = int(input())
myList = list(map(int,input().split()))
capture = [0]*400001
for k in range(size):
    # same offsets, hence the sum will land on the
    # same index. The negative indexes simply move to
    # the other end of the list 
    capture[myList[k]-k] += myList[k]
print (max(capture))
