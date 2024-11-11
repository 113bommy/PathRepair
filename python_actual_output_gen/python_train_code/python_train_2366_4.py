n = int(input())
winner = ''
win_score = -251
for i in range(n):
    current = list(map(str,input().split()))
    score = int(current[1])*100 - int(current[2])*50 + int(current[3]) + int(current[4]) +int(current[5]) +int(current[6]) +int(current[7])
    if score > win_score :
        win_score = score
        winner = current[0]
        
print(winner)