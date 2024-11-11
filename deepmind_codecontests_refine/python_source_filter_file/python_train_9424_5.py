#in the name of god
#Mr_Rubickn=int(input())
a=list(map(int,input().split()))
a.sort()
cnt=0
for i in a:
    if(a[cnt]<i):
        cnt+=1
print(cnt)