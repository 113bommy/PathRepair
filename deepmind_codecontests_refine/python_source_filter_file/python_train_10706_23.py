N=int(input())
e_list = [[] for i in range(N)]
for i in range(N-1):
    a,b=list(map(int,input().split()))
    a,b=a-1,b-1
    e_list[a].append(b)
    e_list[b].append(a)

vi = 0 #時と場合によってここを変える
from collections import deque
Q = deque([vi])
checked_list = [False for i in range(N)]
checked_list[vi]=True
prev_list = [-1 for i in range(N)]
min_path_list = [10**27 for i in range(N)] #問題によりここを変える
min_path_list[vi] = 0
while len(Q)>0:
    v = Q.pop()
    for v1 in e_list[v]:
        if not checked_list[v1]:
            checked_list[v1]=True
            Q.appendleft(v1)
            prev_list[v1]=v
            min_path_list[v1]=min(min_path_list[v1],min_path_list[v]+1) #問題によりここを変える

path = [N-1]
v=N-1
while prev_list[v]!=-1:
    path.append(prev_list[v])
    v=prev_list[v]

a=path[min_path_list[N-1]//2]
b=path[min_path_list[N-1]//2+1]
for i in range(len(e_list[a])):
    if e_list[a][i]==b:
        break
del e_list[a][i]

for i in range(len(e_list[b])):
    if e_list[b][i]==a:
        break
del e_list[b][i]

vi = 0 #時と場合によってここを変える

Q = deque([vi])
checked_list = [False for i in range(N)]
checked_list[vi]=True
count = 1
while len(Q)>0:
    v = Q.pop()
    for v1 in e_list[v]:
        if not checked_list[v1]:
            checked_list[v1]=True
            Q.appendleft(v1)
            count+=1

if count>N-count:
    print("Fennec")
else:
    print("Snuke")