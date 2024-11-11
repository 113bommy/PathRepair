num = int(input())
ans = 0
for i in range(num):
    string = input().split()
    if int(string[1]) >= 2400:
        if int(string[1]) < int(string[2]):
            ans = 1
if ans == 1:
    print("YES")
else:
    print("NO")