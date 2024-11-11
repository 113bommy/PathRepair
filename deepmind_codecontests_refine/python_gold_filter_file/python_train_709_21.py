N,*A=map(int,open(0).read().split());l=[0]*4
for a in A:l[a&3]+=1
o=l[1]+l[3];print("YNeos"[o>1+l[0]or o-1==l[0]and l[2]>0::2])