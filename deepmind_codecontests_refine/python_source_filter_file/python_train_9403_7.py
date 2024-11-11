n_k = input().split()
n = int(n_k[0])
k = int(n_k[1])
scores = input().split()
count = 0
for i in range(n):
    if int(scores[i]) != 0 and i <= k:
        count+=1
    elif int(scores[k]) != 0 and int(scores[i]) == int(scores[k]):
        count+=1
print(count)
