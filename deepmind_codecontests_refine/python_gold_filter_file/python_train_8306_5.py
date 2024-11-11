N = int(input())
A = [[] for i in range(N)]
for n in range(N-1):
    a,b = map(int, input().split())
    A[a-1].append(b-1)
    A[b-1].append(a-1)
#print(A)


from collections import deque
def dfs(node):
    st = deque()
    push, pop = st.append, st.popleft
    push(node)
    cnt = [0]*N
    cnt[node] = 1
    while st:
        now = pop()
        for n in A[now]:
            if cnt[n] == 0:
                push(n)
            cnt[n] = 1
    return now

def dfs_L(node):
    st = deque()
    push, pop = st.append, st.popleft
    push([node,0])
    cnt = [0]*N
    cnt[node] = 1
    L_list = []
    while st:
        [now,L] = pop()
        L_list.append(L)
        for n in A[now]:
            if cnt[n] == 0:
                push([n,L+1])
            cnt[n] = 1
    return max(L_list)
            

step1 = dfs(0)
length = dfs_L(step1)
if length%3 == 1:
    print('Second')
else:
    print('First')