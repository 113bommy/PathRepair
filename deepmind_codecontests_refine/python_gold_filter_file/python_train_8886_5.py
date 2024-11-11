n=int(input())
s=input()
t=0
for i in range(len(s)-1):
    if s[i]==s[i+1]:
        t+=1
print(t)
