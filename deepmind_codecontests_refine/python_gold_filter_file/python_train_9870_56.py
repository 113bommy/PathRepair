A,B = list(map(int,input().split(' ')))
print(int(0 if A<6 else B/2 if A<13 else B))