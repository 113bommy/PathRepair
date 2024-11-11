s = input()
a = 0
s+='#'
arr = ["Olya", "Danil", "Slava", "Ann", "Nikita"]
for i in range(100):
    for j in range(100):
        if (i < j):
            if (s[i:j] in arr):
                a += 1
if (a == 1):
    print("YES")
else:
    print("NO")