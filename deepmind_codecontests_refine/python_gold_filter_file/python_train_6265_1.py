n=int(input())
b=str(input())
stack=["" for i in range(n)]
top=0
for i in range(n):
    if len(stack)==0:
        stack[top]=b[i]
        continue
    if b[i]=="(":
        stack[top]=b[i]
        top+=1
    elif b[i]==")":
        if stack[top-1]=="(":
            top-=1
        else:
            stack[top]=")"
            top+=1
if top==0 or (top==2 and stack[0]==")" and stack[1]=="("):
    print("Yes")
else:
    print("No")
