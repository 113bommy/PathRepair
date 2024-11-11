n=int(input())
stack=[]
for i in range(n):
    a=int(input())
    if a>3:
        stack.append('YES')
    else:
        stack.append('NO')
for j in range(len(stack)) :
    print(stack[j])
