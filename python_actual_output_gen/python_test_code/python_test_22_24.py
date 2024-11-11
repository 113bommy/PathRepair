n, k = map(int, input().split())
teams = 0
members = list(map(int, input().split()))
count = 0
members_avail = []
for i in range(0, len(members)):
     if members[i] < 5 - k:
         members_avail.append(members[i])
a = len(members_avail)
while a >= 3:
       a -= 3
       teams += 1

print(teams)
        
