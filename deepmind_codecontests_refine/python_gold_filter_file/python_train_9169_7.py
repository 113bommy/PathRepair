n = int(input())
inputs = input().split(" ")
for i in range(len(inputs)):
    inputs[i] = int(inputs[i])
l = [0] * 100

for i in range(n):
    l[inputs[i]-1]+=1
max = 0
for i in range(100):
    if(l[i] > max):
        max = l[i]
print(max)
