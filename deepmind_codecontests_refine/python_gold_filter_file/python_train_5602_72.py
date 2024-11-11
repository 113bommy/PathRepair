A,B =map(int,input().split())
l =[A,A-1,B,B-1]
l.sort()
print(l[2]+l[3])