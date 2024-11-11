n=int(input())
l=list(map(int,input().split()))
an=[0]
for i in l:
    an.append(an[-1]+i)
a,b=list(map(int,input().split()))
print(l[b-1]-l[a-1])