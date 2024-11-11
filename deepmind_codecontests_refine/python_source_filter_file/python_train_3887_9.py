n=int(input())
l= list(map(int,input().split()))
s,count=0,0
total=0
for i in l:
    total+=i


while(s<=(total//2)+1):
    s+=max(l)
    count+=1
    l.remove(max(l))
print(count)