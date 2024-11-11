n=int(input())
s=list(map(int,input().split()))
output=[len(s)]*len(s)
stack=[]
stack.append(0)
for i in range(1,len(s)):
    if stack and s[stack[-1]]<=s[i]:
        stack.append(i)
    else:
        while stack and s[stack[-1]]>s[i]:
            output[stack[-1]]=i 
            stack.pop()
        stack.append(i)
output1=[-1]*len(s)
stack=[]
stack.append(len(s)-1)
for i in range(len(s)-2,-1,-1):
    if stack and s[stack[-1]]<=s[i]:
        stack.append(i)
    else:
        while stack and s[stack[-1]]>s[i]:
            output1[stack[-1]]=i 
            stack.pop()
        stack.append(i)
res=[0]*(len(s)+1)
for i in range(len(s)):
    res[output[i]-output1[i]-1]=max(res[output[i]-output1[i]-1],s[i])
for i in range(len(res)-2,-1,-1):
    res[i]=max(res[i],res[i+1])
print(res[1:])