n,b= map(int,input().split())
l=list(map(int,input().split()))
cut= []
if n==0 or n%2==1:
    print(0)
else:
    odd=0
    even=0
    for i in range(n-1):

        if l[i]%2==0:
            even+=1
            if odd==even:
                cut.append(abs(l[i]-l[i+1]))
        else:
            odd+=1
            if odd==even:
                cut.append(abs(l[i]-l[i+1]))
cut=sorted(cut)
count=0
for j in range(len(cut)):
    if b-cut[j]>0:
        count+=1
        b-=cut[j]
    else:
        break


print(count)