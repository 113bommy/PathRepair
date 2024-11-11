_,t=input(),sorted(int(x) for x in input().split())
s,h=0,0
for i in range(len(t)):
    if s<=t[i]:
        h+=1
        s+=t[i]
print(h)