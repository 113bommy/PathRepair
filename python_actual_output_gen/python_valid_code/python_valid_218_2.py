a,b,c=map(int,input().split())
k=int(input())
res="No"
for i in range(k):
    if a>b:
        b*=2
    else:c*=2
if a<b<c:res="Yes"
print(res)