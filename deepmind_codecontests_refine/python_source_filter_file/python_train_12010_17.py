n = int(input())
li = list((map (int, input().strip().split())))
li.sort()

fi = li[0]
flag = 0;
for i in range(0, len(li)):
    if fi != li[i]:
        flag = 1
        print(li[i])
        break
if(flag == 0):
    print("-1")