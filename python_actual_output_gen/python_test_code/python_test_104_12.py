import sys
x = []
j = 0
x1 = int(input())
for _ in range(x1):
    x2,x3 = input().split()
    x.append(int(x2))
    x.append(int(x3))
    if int(x3)-int(x2) > 0:
        j+=1
if j>=1:
    print("rated")
    sys.exit()
if x==sorted(x,reverse=True):
    print("maybe")
    sys.exit()
else:
    print("unrated")
