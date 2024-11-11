n=int(input())
stack=[]
for i in range(n):
    a=int(input())
    if a%4==0:
        stack.append('YES')
    else:
        stack.append('NO')
for j in range(len(stack)) :
    print(stack[j])