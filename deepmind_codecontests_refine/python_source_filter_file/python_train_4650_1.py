firstLine = input().strip().split(" ")
n = int(firstLine[0])
k1 = int(firstLine[1])
k2 = int(firstLine[2])

A = list(map(int,input().strip().split(" ")))
B = list(map(int,input().strip().split(" ")))

def findErrorInRankingTable():
    error = 0
    for item in rankingTable:
        error += (item[3])**2
    return error
    
"""Apply the addition or subtraction to the largest difference so that it minimizes error."""

"""Rank: 0 1 2 3
         A 
         B   
         D
"""
rankingTable = []
for i in range(n):
    difference = A[i]-B[i]
    rankingTable.append([i,A[i],B[i],difference**2])

#Sort the rankings by difference.    
rankingTable.sort(key = lambda item: item[3])

#print(rankingTable)
#apply the k1 operations.
for i in range(k1):
    #Move the a value closer to the b value.
    if rankingTable[n-1][1] < rankingTable[n-1][2]:
        rankingTable[n-1][1] += 1
    else:
        rankingTable[n-1][1] -= 1
    #Recalculate difference.
    rankingTable[n-1][3] = (rankingTable[n-1][1] - rankingTable[n-1][2])**2
    #print(rankingTable)
    #Percolate new largest difference up if needed.
    rankingTable.sort(key = lambda item: item[3])

#apply the k2 operations.
for i in range(k2):
    #Move the a value closer to the b value.
    if rankingTable[n-1][2] < rankingTable[n-1][1]:
        rankingTable[n-1][2] += 1
    else:
        rankingTable[n-1][2] -= 1
    #Recalculate difference.
    rankingTable[n-1][3] = (rankingTable[n-1][1] - rankingTable[n-1][2])**2
    #print(rankingTable)
    #Percolate new largest difference up if needed.
    rankingTable.sort(key = lambda item: item[3])    
    
#print(rankingTable)  
print(findErrorInRankingTable())