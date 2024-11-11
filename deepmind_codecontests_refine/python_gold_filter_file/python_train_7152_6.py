s = list(set(input().split(".")))
l = ["ABC", "ACB", "BCA", "BAC", "CBA", "CAB"]
for i in s:
    for j in l:
        if j in i:
            print("Yes")
            exit(0)
print("No")
