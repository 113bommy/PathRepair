import sys;

v,e=map(int, input().split());

v_l=[0]*v;
e_b=[0]*e;
e_l=[0]*e;
result=0;

for i in range(v):
    v_l[i] = 0;
for i in range(e):
    e_b[i], e_l[i] = map(int, input().split());

def DFS(u):
    global result
    global v_l
    v_l[u] = 1
    for i in range(e):
        if(e_b[i] == u):
            if(v_l[e_l[i]] == 0):
                DFS(e_l[i])
            if(v_l[e_l[i]] == 1):
                result=1
    v_l[u] = 2
for i in range(v):
    DFS(0)
print(result)

