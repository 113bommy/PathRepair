nm=input().split(" ")
n=int(nm[0])
m=int(nm[1])
blich=[]
for i in range(n):
    blich.append(list(input()))
nl=[0,0]
nr=[0,0]
sl=[0,0]
sr=[0,0]
dflt=(-1,-1)

num=0
for i in range(n):
    for j in range(m):
        if blich[i][j] == "B":
            if num>0:
                num+=1
            elif num==0:
                num+=1
                nl=[i,j]
                nr=[i,j]
                sl=[i,j]
                sr=[i,j]
for i in range(n):
    for j in range(m):
        if blich[i][j] == "B":
            if i < nl[0]: nl[0] = i
            if j < nl[1]: nl[1] = j

            if i < sl[0]: sl[0] = i
            if j > sl[1]: sl[1] = j

            if i > nr[0]: nr[0] = i
            if j < nr[1]: nr[1] = j

            if i > sr[0]: sr[0] = i
            if j > sr[1]: sr[1] = j

lastfm1=[max(nr[0],nl[0],sr[0],sl[0]),max(nr[1],nl[1],sr[1],sl[1])]
lastfm2=[min(nr[0],nl[0],sr[0],sl[0]),min(nr[1],nl[1],sr[1],sl[1])]
fm1=lastfm2[1]-lastfm1[1]+1
fm2=lastfm2[0]-lastfm1[0]+1
fm=max(fm1,fm2)
if fm>n or fm>m:
    print(-1)
else:
    print(fm*fm-num)
