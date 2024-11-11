a, b = list(map(int, input().split()))
flag = False
for i in range(a+1, b):
    if len(set(str(i))) == len(str(i)):
        print(i)
        flag = True
        break
if not flag:
    print(-1)
