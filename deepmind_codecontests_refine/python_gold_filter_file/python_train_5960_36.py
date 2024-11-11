import sys
def input():    return sys.stdin.readline().strip()

n,m,k = map(int,input().split(" "))
for i in range(2*n):    input()
S = "U"*(n-1) + "L"*(m-1)
T = [(m-1)*"R",(m-1)*"L"]
i=0
while i<n:
    S +=T[i%2]
    i+=1
    if i == n:
        break
    S += "D"
    S +=T[i%2]
    i+=1
    if i==n:
        break
    S+="D"
print(len(S))
print(S)

