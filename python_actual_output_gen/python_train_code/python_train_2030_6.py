n = int(input())
oriStatus = str(input())
lockPass = str(input())
def minDifference(a, b):
    a = int(a)
    b = int(b)
    (a,b) = (a,b) if a < b else (b,a) 
    return b-a if (b-a) < (a + 10 - b) else a + 10-b
def totalMoves(sum, index):
    return sum + index
sum = 0
k=len(oriStatus) 
for i in range(0,k):
    sum = totalMoves(sum,minDifference(oriStatus[i],lockPass[i]))
print(sum,k)
