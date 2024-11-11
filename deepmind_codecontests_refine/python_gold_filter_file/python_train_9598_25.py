s = str(input())
e = s.split(" ")
count = 0
maximum = int(e[0])-1
minimum = 0
k=True
count=0
while k == True:
    if maximum >= int(e[1]) and minimum <= int(e[2]):
        count+=1
        maximum-=1
        minimum+=1
    else:
        k=False
print(count)