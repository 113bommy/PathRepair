a,b=list(map(int, input().split()))
c=map(int, input().split())
cnt=0
for i in c:
   if (i+b)<+5:
      cnt+=1

print(cnt//3)      
