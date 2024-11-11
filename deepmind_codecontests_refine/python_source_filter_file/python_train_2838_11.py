a=int(input())
for i in range(a):
    o=list(map(int,(input().split())))
    o.sort()
    if o[1]==o[2]:
        print("YES")
        print(o[0],o[0],1)
    else:
        print("NO")
    