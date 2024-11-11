#ZadB
n,A,B=map(int, input().split())
holes=list(map(int, input().split()))
#schital input
s1=holes[0]
holes.remove(s1) #udalim pervuy dyrku
holes.sort(reverse=1)
summ=s1
ans=0
for i in range(0,len(holes)):
    summ+=holes[i]
    if summ>((s1*A)/B):
        ans=len(holes)-i
        break
print(ans)    