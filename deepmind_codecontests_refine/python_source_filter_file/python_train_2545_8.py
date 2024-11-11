# cook your dish
a=list(map(int, input().split()))
if (a[0] != a[2] and a[1] != a[3] and abs(a[0] - a[2]) != abs(a[1] - a[3])):
    print(-1)
if a[0]==a[2]:
    # or a[1]==a[3] or a[2]==a[3]:
    print(a[0]+abs(a[3]-a[1]), a[1], a[2]+abs(a[3]-a[1]), a[3])
elif a[1]==a[3]:
    print(a[0], a[1]+abs(a[0]-a[2]), a[2], a[3]+abs(a[0]-a[2]))
else:#if a[2]==a[3] and a[0]==a[1]:
    print(a[0], a[2], a[2], a[0])
    