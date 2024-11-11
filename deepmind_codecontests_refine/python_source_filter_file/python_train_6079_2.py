from sys import stdin, stdout
# The answer to the query li, ri is the number of
# such integers i (li ≤ i < ri), that si = si + 1.

A = str(stdin.readline().split()[0])

DP = (len(A)) * [0]


def build_rsq(n):
    for i in range(1, n-1):

        DP[i] = DP[i-1]
        if A[i] == A[i-1]:

            DP[i] = DP[i] + 1


    DP[n-1] = DP[n-2] + 1

def rsq(l,r):
    

    return int(DP[r] - DP[l])        
        

build_rsq(len(A))
#print(DP)
numbers_cases = int(stdin.readline())
for i in range(0, numbers_cases):

    query = list(stdin.readline().strip().split(' '))
 
    stdout.write(str(rsq(int(query[0])-1,int(query[1])-1))+'\n')  
