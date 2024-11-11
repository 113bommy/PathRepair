from collections import defaultdict


n, d = map(int, input().split(' '))



friends = []
for i in range(n):
    m, s = map(int, input().split(' '))
    friends.append((m, s))

# sort in n * log n
friends.sort()
friendship_factor = 0
slow, fast = 0, 0
money_difference = 0
current_friendship = 0
while fast < n:
    current_friendship += friends[fast][1]
    while friends[fast][0] - friends[slow][0] > d and slow < fast:
        current_friendship -= friends[slow][1]
        slow += 1
    friendship_factor = max(friendship_factor, current_friendship)
    fast += 1
print(friendship_factor)
        