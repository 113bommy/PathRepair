s = input()
k = int(input())
ans = "1"
for i in s[:k]:
    if i!= "1":
        ans = i
        exit()
print(ans)