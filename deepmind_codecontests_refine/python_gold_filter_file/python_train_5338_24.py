from collections import deque
n=int(input())
a=deque(sorted(map(int,input().split())))
b=[]
while a:
    b.append(a.pop())
    if a:
        b.append(a.popleft())
ct=0
for i in range(1,n-1):
    if b[i]<b[i+1] and b[i]<b[i-1]:
        ct+=1
print(ct)
print(*b)
    