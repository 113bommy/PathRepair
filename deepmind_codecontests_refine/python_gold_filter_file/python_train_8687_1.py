def sum_ones(n):
    count = 0
    while(n!=0):
        n &= (n-1)
        count+=1
    return count


n,m,k = map(int,input().split())
players = []
for i in range(m+1):
    players.append(int(input()))
fedor = players.pop()
count=0
for player in players:
    if sum_ones(fedor ^ player) <= k:
        count+=1
print(count) 
