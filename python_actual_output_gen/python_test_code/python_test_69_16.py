n, k = map(int, input().split())
A = [int(s) for s in input().split()]

MAX = max(A)
count = 0
player = 0

for i in range(n):
    if(A[i] == MAX):
        print(MAX)
        break
    elif(A[i] > player):
        if(i > 0):
            count = 1
            player = A[i]
    else:
        count += 1
    if(count == k):
        print(player)
        break
    


