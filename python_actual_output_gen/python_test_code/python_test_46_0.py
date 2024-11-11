N = int(input())
X = 0
Y = 0
for i in range(2*N):
    tmp = [ int(i) for i in input().split()]
    X+= tmp[0]
    Y+= tmp[1]
print(int(X/2), int(Y/2))