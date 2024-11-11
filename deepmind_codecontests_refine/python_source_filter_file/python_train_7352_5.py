n = int(input())
line = input().split()
claw = [i - int(line[i]) for i in range(n)]
count = 1
die = claw[-1]
for i in range(n - 1,0,-1):
    if i < die:
        count += 1
    die = min(die,claw[i])
print(count)
