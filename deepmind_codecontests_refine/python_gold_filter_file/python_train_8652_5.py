n,k=[int(x) for x in input().split()]
s=[int(x) for x in input().split()]
counter={}
for item in s:
    if item not in counter:
        counter[item]=1
    else:
        counter[item]+=1
total_counter=[]
for item in counter:
    total_counter.append((counter[item],item))
total_counter.sort(reverse=True)
what=[]
left=0
right=n+1
answer=[]
while right-left>1:
    kpob=k
    maybe=0
    what=[]
    middle=(left+right)//2
    for item in range(min(k,len(total_counter))):
        maybe+=total_counter[item][0]//middle
        for i in range(min(total_counter[item][0]//middle,kpob)):
            what.append(total_counter[item][1])
            kpob-=1
        if maybe>=k:
            left=middle
            answer=what[:]
            break
    else:
        right=middle
print(*answer)
