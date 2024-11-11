t=int(input())
stack=[]
stack.append(1)
ans=0 
mm=(1<<32)-1
# print(mm)
for i in range(t):
    s=list(map(str,input().split()))
    if s[0]=="add":
        ans+=stack[-1]
    elif s[0]=="for":
        k=int(s[1])
        stack.append(min(mm,k*stack[-1]))
    else:
        stack.pop()
if ans>mm:
    print("OVERFLOW!!!")
    exit()
print(ans)