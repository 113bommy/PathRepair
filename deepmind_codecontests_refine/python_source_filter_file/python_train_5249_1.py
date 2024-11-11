m,k = list(map(int,input().split()))[1:];s=0
for i in input().split():
    if i == "1" and m>0: m-=1
    if i == "2" and k>0: k-=1
    elif i == "2" and m>0: m-=1
    else: s+=1
print(s)