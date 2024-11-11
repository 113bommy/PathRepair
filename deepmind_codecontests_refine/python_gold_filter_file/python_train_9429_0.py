n = int(input())
a = list(map(int, input().split()))
a.sort()
f = False
for i in range(0, n-2):
    t = a[i:i+3]
    if (t[0] + t[1])>t[2]:
        print("YES")
        f = True
        break
    #print(t)
if not f:
    print("NO")