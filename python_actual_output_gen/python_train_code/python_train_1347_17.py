s = str(input())
l = ""
for i in s:
    if i == "4":
        l+= "0"
    else:
        l+= "1"

sum = 0
for i in range(0, len(s)):
    sum+= 2**i


sum+=int(l, 2)
print(l)
print(sum)