n,k = map(int,input().split())
num = list(map(int,input().split()))
if k >= 3:
    print(max(num))
elif k== 1:
    print(min(num))
else:
    print(min(num[0],num[-1]))