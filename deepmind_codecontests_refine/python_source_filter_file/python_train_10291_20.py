a,b=map(int,input().split())
L=[1,3,4,7,8,10,12]*3+[4,6,9,11]*2+[2]
print(['No','Yes'][L.count(a)==L.count(b)])