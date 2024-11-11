h,w=map(int, input().split())
p=[int(input()) for i in range(w)]
q=[int(input()) for i in range(h)]
p.append(0)
q.append(0)
p.sort()
p.reverse()
q.sort()
q.reverse()

count=h*w
row=0
line=0
i=0
j=0
ans=0

while count>0:
    if p[i]>=q[j]:
        ans+=p[i]*(w-line)

        count-=w-line
        i+=1
        row+=1

    else:
        ans+=q[j]*(h-row)

        count-=h-row
        j+=1
        line+=1
x=sum(p)*(h+1)+sum(q)*(w+1)
print(x-ans)
