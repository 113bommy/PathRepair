total_friend,height_fence=map(int,input().split())
hei=list(map(int,input().split()))
wi=0
for j in range(total_friend):
    if hei[j]<height_fence:
        wi+=1
    else:
        wi+=2
print(wi)