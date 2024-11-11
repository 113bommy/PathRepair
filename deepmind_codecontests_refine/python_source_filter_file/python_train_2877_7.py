from collections import deque

n = int(input())
p = list(map(int, input().split()))

arr = []

c = deque([])
c.extend(list(map(int, input().split())))
c.extendleft([0])
#print(c)

arr = deque([])
arr.extend([list() for i in range(n)])
arr.appendleft([1])
#print(arr)

for i in range(2, n+1):
    arr[p[i-2]].append(i)
    
stack = [[1, c[1]]]
#print(stack)

ans = 1

flag_for_break = 0

while stack != []:
    flag_for_break += 1
    
    x, color = stack.pop(0)
    
    #print('x =', x)
    #print('color =', color)
    
    for elem in arr[x]:
        if c[elem] != color:
            ans += 1
            
        stack.append([elem, c[elem]])
        #print(stack)
        
    if flag_for_break > 1000:
        break
        
#print("====")
print(ans)