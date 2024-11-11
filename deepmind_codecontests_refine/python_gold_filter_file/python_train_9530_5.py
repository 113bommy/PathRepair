n = int(input())
t = 0
for i in range (n):
    s , a , b = input().split(' ')
    if (int(a) >= 2400 and int(a) < int(b)):
        print("YES")
        t = 1
        break
if (t == 0):
    print("NO")