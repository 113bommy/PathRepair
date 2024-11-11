#codeforceに対して最大40文字(ずつ)らしい
#なるべく均等に増やすのが吉。ので理想系は(p**n)*
#((p-1)**(9-n))
k=int(input())
l=1
r=40
while l+1!=r:
    m=(l+r)//2
    x=m**9
    if x>k:
        r=m
    elif x==k:
        l=m
        r=m+1
    else:
        l=m
p=l**9
exp=0
while p>k:
    p=p//l*r
    exp+=1
ls=[]
for i in "codeforces":
    if exp==0:
        ls.extend([i]*l)
    else:
        ls.extend([i]*r)
        exp-=1
print("".join(ls))