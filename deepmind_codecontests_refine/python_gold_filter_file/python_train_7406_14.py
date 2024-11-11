n = int(input())
s = list(map(int, input().split(' ')))
max = 0
sf = sl = 0
i = 0
temp = 0
while s[i] != 0:
    sf += 1
    i+=1
i = n-1
while s[i] != 0:
    sl += 1
    i -= 1
for i in range(len(s)-1):
    if s[i] == 1:
        temp += 1
        if s[i+1]!=1:
            if temp > max:
                max = temp
            temp = 0
print(max) if sl + sf < max else print(sl+sf)
