n = int(input())
for i in range (n):
    s , a , b = input().split(' ')
    if int(a) >= 240 and int(a) < int(b):
        print("YES")
        t = 1
        break
if (t == 0):
    print("NO")