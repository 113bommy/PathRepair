n = int(input())
a = list(map(int,input().split()))
a.sort()
t = 1
for i in a:
    if i!= t :
        print(t)
        exit()
    else: t+=1
print(n + 1)