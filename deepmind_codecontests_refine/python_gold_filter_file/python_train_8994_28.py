from re import split
num = input()
num = split(r"\s" , num)
if num[1] == '0':
    print("YES")
    exit()
inp = input()
inp = split(r"\s" , inp)
for k in range(int(num[1])):
    inp[k] = int(inp[k])
inp.sort()
i = 0
temp1 = False
temp2 = False
m = int(num[1])
n = int(num[0])
while i+1 < m:
    if int(inp[i+1]) - int(inp[i]) == 1:
        if temp1:
            temp2 = True
            break
        else:
            temp1 = True
    else:
        temp1 = False
    i += 1
if temp2 or inp[0] == 1 or int(inp[m-1]) == n: 
    print("NO")
else:
    print("YES")
    