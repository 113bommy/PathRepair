s = ''
a = [0]
for i in input():
    a.append(a[-1] + (1 if s == i else 0))
    s = i
    #print(a,s)
for i in range(int(input())):
    l, r = map(int, input().split())
    print(a[r]-a[l])