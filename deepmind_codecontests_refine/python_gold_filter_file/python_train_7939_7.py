n=int(input())
l=list(map(int,input().split()))
lena=(len(l))

l.sort()
left=l[:lena//2]
right=l[lena//2:]
left.sort();right.sort()
answer=[]
count=0
for i in range(len(right)):
    answer.append(right[i])
    if i<len(left):
        answer.append(left[i])
        if answer[-1]<answer[-2] and i<len(right)-1:
            count+=1
print(count)
print(*answer)