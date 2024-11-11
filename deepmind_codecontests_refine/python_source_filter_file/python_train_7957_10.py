li=['a', 'b', 'c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
s= input()
k= int(input())
l= list(map(int, input().split()))

dic={}
for i in range(26):
    dic[li[i]]=l[i]

ans=0
temp=1
for i in range(len(s)):
    ans+= temp*l[i]
    temp+=1

m= max(l)
for i in range(k):
    ans+=temp*m
    temp+=1

print(ans)