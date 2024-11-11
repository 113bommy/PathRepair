n = int(input())
string = input()
a = 1
for x in range(n):
    if string[0] == "1":
        string = string.replace("1", "", 1)
        a += 1
    else:
        break
if a == n - 1:
    a == n
print(a)