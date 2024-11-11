n = list(input())

for i in n:
    if n.count(i)%2 != 0:
        print("N0")
        exit()
print("Yes")
