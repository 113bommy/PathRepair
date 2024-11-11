n=int(input())
a=list(map(int,input().split()))
s1=set()
s2=set()
for i in a:
    
    s1={i|j for j in s1}
    s1.add(i)
    s2.update(s1)
    
print(len(s2))