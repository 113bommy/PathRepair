n=int(input())
s=list(map(int,input().split()))
e=[]
b=1
for i  in range(n-1):
       if s[i]==s[i-1]:
              b+=1
       else:
              e.append(b)
              b=1
e.append(b)
h=0
for i in range(len(e)-1):
       h=max(h,min(e[i],e[i+1]))
print(2*h)