# cook your dish here
s = sum(list(map(int,input().split())))
if (s%5)==0:
    print(s//5)
else:
    print(-1)