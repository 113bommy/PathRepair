n = int(input())
a = [int(i) for i in input().split()]
if n>len(set(a)):
    print("NO")
else:
    curr,verdict = a[0],True
    if a[1]>curr:
        up = True
        down = False
        mark = 0
        for i in range(1,n):
            if a[i]<curr:
                up = False
                down = True
                mark = i
                break
            curr = a[i]
        for i in range(mark,n):
            if a[i]>curr:
                verdict = False
                break
            curr = a[i]
    else:
        down = True
        for i in range(1,n):
            if a[i]>curr:
                verdict = False
                break
            curr = a[i]
    if verdict:print("YES")
    else:print("NO")
    