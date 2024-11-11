s=input()
k=int(input())
a=input().split()
l=[]
sm=0
b=['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
for i in range(26):
    l.append(int(a[i]))
for i in range(len(s)):
    sm+=l[b.index(s[i])]*(i+1)

for i in range(k):
    sm+=max(l)*(len(s)+1+i)
print(sm)
