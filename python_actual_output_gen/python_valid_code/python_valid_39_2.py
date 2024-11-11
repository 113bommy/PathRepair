n = int(input())
d  =list(map(int,input().split()))
d.sort()
m = int(input())
t = list(map(int,input().split()))
t.sort()
for x in t:
    while d[i] < x:
        i += 1
    if d[i] == x:
        i += 1
    else:
        print("NO")
        exit()
print("YES")