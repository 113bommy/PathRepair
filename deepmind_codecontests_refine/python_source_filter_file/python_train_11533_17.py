from collections import deque
h,w=map(int,input().split())
cx,cy=map(int,input().split())
cx+=1
cy+=1
dx,dy=map(int,input().split())
dx+=1
dy+=1
l=[]
l.append("#"*(w+4))
l.append("#"*(w+4))
for i in range(h):
    l.append("##"+input()+"##")
l.append("#"*(w+4))
l.append("#"*(w+4))
#input

"""
for i in l:
    print(*i)
"""

q=deque([[cx,cy]])
qq=deque([[cx,cy]])
s=[[-1 for i in j]for j in l]
s[cx][cy]=0

while len(qq)>0:
    while len(q)>0:
        x,y=q.popleft()
        for px,py in ((0,1),(0,-1),(1,0),(-1,0)):
            if l[x+px][py+y]=="." and s[x+px][y+py]==-1:
                s[x+px][y+py]=s[x][y]
                q.appendleft([x+px,y+py])
                qq.appendleft([x+px,y+py])
    x,y=qq.popleft()
    for px in range(-2,3):
        for py in range(-2,3):
            if l[x+px][py+y]=="." and s[x+px][y+py]==-1:
                s[x+px][y+py]=s[x][y]+1
                q.append([x+px,y+py])
                qq.append([x+px,y+py])
"""
for i in s:
    print(*i)
"""

print(s[dx][dy])