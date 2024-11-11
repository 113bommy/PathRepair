n = int(input())

a = list(map(int,input().split()))

b ={i:0 for i in range(min(min(a),-1),max(a)+10)}
for i in a:
    b[i] += 1

c = 0
for i in range(1,len(b)-3):
    c = max(c,b[i]+b[i+1]+b[i+2])
print(c)