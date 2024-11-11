x, y = map(int, input().split())
inp = list(map(int, input().split()))
frnds = inp[:x]
count = 0
for i in frnds:
    if(i<y):
        count += 1
    else:
        count += 2
print(count)