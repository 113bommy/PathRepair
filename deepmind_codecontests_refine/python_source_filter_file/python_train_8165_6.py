n = int(input().strip())
l = [0]*100002

for x in input().split():
    l[int(x)] += int(x)

max = l[1]

for i in range (2,len(l)):
    if l[i-2] + l[i] > max:
        max = l[i-2] + l[i]
        l[i] = max

print (max)