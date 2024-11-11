l=list(map(int,input().split(' ')))
print(min(l[5]-l[4]+1,max(0,min(l[:4])-l[4])))
