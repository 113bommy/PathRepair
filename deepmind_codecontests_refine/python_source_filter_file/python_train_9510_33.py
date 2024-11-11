n = int(input())
k = list(map(int, input() .split()))
mini = min(k)
length = len(k)
count = 0
y = 0
for x in range(0, length):
    if k[x]==mini:
        count = count+1
    
if count>1:
    print("Still at Rozdil")
else:
    print(k.index(mini)+1)