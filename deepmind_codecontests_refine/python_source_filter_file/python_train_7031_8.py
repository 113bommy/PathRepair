l=list(map(int,input().split(' ')))
print(min(l[5],max(0,min(l[:4])-l[4])))
