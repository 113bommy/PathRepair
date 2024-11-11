s = int(input())
arr = list(map(int,input().split()))
stack = []
for data in arr:
    
    if stack and stack[-1] == data%2:
        stack.pop(-1)
    else:
        stack.append(data%2)
    
  

if len(stack)<=1:
    print("YES")
else:
    print("NO")