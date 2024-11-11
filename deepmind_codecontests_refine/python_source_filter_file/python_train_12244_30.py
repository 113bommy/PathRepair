from collections import Counter
n,a=list(map(int,input().split(" ")))
b=input()
c=Counter(b)
# print(c)
for y in list(c.values()):
    if(y>n):
        print("NO")
        # break
        exit()
print("YES")