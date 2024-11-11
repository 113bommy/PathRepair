s=input()
for c in range(len(s)):
    if s[c]=='[':
        break
if c==len(s)-1:
    print("-1")
    exit(0)
else:
    s=s[c:]
for c in range(len(s)-1,-1,-1):
    if s[c]==']':
        break
if c==0:
    print("-1")
    exit(0)
else:
    s=s[:c+1]
count=0
x=[c for c in range(len(s)) if s[c]==':']
if len(x)<2:
    print("-1");exit(0)
for c in range(x[0]+1,x[-1]):
    if s[c]=='|':
        count+=1
print(count+4)