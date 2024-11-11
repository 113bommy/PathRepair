n= int(input())
l = list(map(int,input().split(" ")))
l.sort()

if(l[0] == 1):
    print("-1")
else:
    print(l[0]-1)
