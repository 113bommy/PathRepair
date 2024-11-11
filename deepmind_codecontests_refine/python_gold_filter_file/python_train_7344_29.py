n,b,d = [int(x) for x in input("").split()]
a = [int(x) for x in input("").split()]
currJuice = 0
ans = 0
for i in a:
    if i <= b:
        currJuice += i
    if currJuice > d:
        ans+=1
        currJuice = 0
print(ans)
