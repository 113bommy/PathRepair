n = int(input())
boxs = list(map(int,input().split()))

tot = sum(boxs)
num = tot // n

s = 0
for i in range(n-1):
    if boxs[i] < num :
        
        boxs[i+1] = boxs[i+1] - (num - boxs[i])
        s += num - boxs[i]
        boxs[i] = num
    elif boxs[i] > num :
        boxs[i+1] = boxs[i+1] + (boxs[i] - num)
        s += boxs[i] - num
        boxs[i] = num
print(int(s))