loop = int(input())
sums = 0
for i in range(loop):
    s = str(input())
    e = s.split(" ")
    a=0
    for j in range(len(e)):
        if e[i:i+1] =="1":
            a+=1
    if a>=2:
        sums+=1
print(sums)