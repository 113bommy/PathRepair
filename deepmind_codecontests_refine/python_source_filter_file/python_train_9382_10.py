s = int(input())
arr = list(map(int,input().split()))
stack = []
for data in arr:
    
    if stack and stack[-1] == data:
        stack.pop(-1)
    else:
        stack.append(data)
    
  

if len(stack)<=1:
    print("YES")
else:
    print("NO")