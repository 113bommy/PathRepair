size = int(input())
s = input()

for i in range(2, len(s) + 1) :
    if size % i == 0 :
        temp1 = "".join(reversed(s[0 : i]))
        temp2 = "".join(s[0 : i])
        s = s.replace(temp2, temp1, 1)
print(s)