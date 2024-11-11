def how(c):
    if float(c).is_integer() == True:
        return int(float(c)),0
    else:
        dot=0
        while c[dot]!=".":
            dot+=1
        c = list(c)
        del c[dot]
        c ="".join(c)
        return int(c),len(c)-dot

def lo2(n):
    count = 0
    while n%2==0:
        n=n//2
        count+=1
    return count

def lo5(n):
    count=0
    while n%5==0:
        n=n//5
        count+=1
    return count

N = int(input())

A = []

for i in range(N):
    A.append(how(input()))


ruiseki = [[0]*80 for i in range(80)]

motoseisuu=0
for i in range(N):
    ruiseki[A[i][1]-lo2(A[i][0])+60][A[i][1]-lo5(A[i][0])+60]+=1
    if A[i][1]==0:
        motoseisuu +=1

for i in range(1,80):
    for j in range(1,80):
        ruiseki[i][j]=ruiseki[i-1][j]+ruiseki[i][j-1]-ruiseki[i-1][j-1]+ruiseki[i][j]


ans = 0
for i in range(N):
    ans+=ruiseki[lo2(A[i][0])+60-A[i][1]][lo5(A[i][0])+60-A[i][1]]

print((ans-motoseisuu)//2)
