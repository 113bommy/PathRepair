n = int(input())
c = input()
k = [0, 0]
if c[0] == "U":
    country = "LEFT"
    co = "LEFT"
else:
    country = "RIGHT"
    co = "RIGHT"
s = 0
for i in c:
    if i == "U":
        k[1] += 1
        if k[0] > k[1]:
            country = "RIGHT"
        if k[0] < k[1]:
            country = "LEFT"
        if (country != co):
            s += 1
        co = country
        
        
    elif i == "R":
        k[0] += 1
        if k[0] > k[1]:
            country = "RIGHT"
        if k[0] < k[1]:
            country = "LEFT"
        if (country != co):
            s += 1
        co = country            
print(s)