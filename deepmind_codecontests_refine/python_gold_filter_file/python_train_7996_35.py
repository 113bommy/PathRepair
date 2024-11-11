s_list = list(input())
k = int(input())
for s in s_list[:k]:
    if s != "1":
        print(s)
        exit()
print(1)
