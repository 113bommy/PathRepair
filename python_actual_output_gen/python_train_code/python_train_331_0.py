s = [int(ch) for ch in input()]
ss = [int(ch) for ch in input()]
if s==[0] and ss==[0]:
    print("OK")
    exit()
s.sort()
ans=[]
for i in range(len(s)):
    if s[i]!=0:
        ans.append(s[i])
        break
for j in range(i):
    ans.append(0)
for k in range(i+1,len(s)):
    ans.append(s[k])
print(ans) 
if ans==ss:
    print("OK")
else:
    print("WRONG_ANSWER")
        