a,b=map(int,input().split())
e=[]
for i in range(a):
    c,d=map(int, input().split())
    e+=[[c,d]]
e.sort()
a=i=j=0
while i < b:
    a+=(e[j][0]*e[j][1])
    i+=e[j][1]
    j+=1
print(a-((i-b)*e[j-1][0]))