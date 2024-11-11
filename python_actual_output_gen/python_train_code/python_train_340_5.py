n =  int(input())
score = list(map(int,input().split()))
count = 0
for i in range(n):
    if i==0:
        continue
    max_score = max(score[:i])
    min_score = min(score[:i])
    
    if score[i]>max_score:
        print("max",score[i],max_score)
        count+=1
    if score[i]<min_score:
        print("min",score[i],min_score)
        count+=1
print(count)
