N = int(input())
l = list(map(int,input().split()))
count = 0
a = []
for i in l:
    if i not in a:
        a.append(i)
for i in l:
    if a.count(i) > count:
        count = l.count(i)
print(count,len(a))
