n = int(input())
a = set(map(int,input().split()))
k = sorted(a)
cnt = 0
for i in range(0,91):
    if i not in a:
        cnt+=1
    else:
        cnt = 0
    if cnt==15:
        if i==14:
            print(15)
            quit()
        print(i)
        quit()
print(90)