def mp():
    return map(int,input().split())
def lt():
    return list(map(int,input().split()))
def pt(x):
    print(x)

def ip():
    return int(input())
class Stack(object):
    def __init__(self):
        self.items = []
    def push(self,new):
        self.items.append(new)
    def pop(self):
        return self.items.pop()
    def empty(self):
        return self.items == []
        
n,m = mp()
Rail = [[] for i in range(n)]
Road = [[i for i in range(n)] for j in range(n)]
for i in range(m):
    u,v = mp()
    Rail[u-1].append(v-1)
    Rail[v-1].append(u-1)
    Road[u-1].remove(v-1)
    Road[v-1].remove(u-1)
visited = [False]*n
time = [float("inf")]*n
if n-1 in Road[0]:
    Q = Stack()
    Q.push(0)
    visited[0] = True
    time[0] = 0
    while not Q.empty() and not visited[n-1] :
        r = Q.pop()
        for i in Rail[r]:
            if not visited[i]:
                visited[i] = True
                time[i] = time[r] + 1
                Q.push(i)
    if not visited[n-1]:
        print(-1)
    else:
        print(time[n-1])
else:
    Q = Stack()
    Q.push(0)
    visited[0] = True
    time[0] = 0
    while not Q.empty() and not visited[n-1]:
        r = Q.pop()
        for i in Road[r]:
            if not visited[i]:
                visited[i] = True
                time[i] = time[r] + 1
                Q.push(i)
    if not visited[n-1]:
        print(-1)
    else:
        print(time[n-1])
    
        
        
        


    
        


    
    
        
    
    
        

    
    