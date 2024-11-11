tv1=-1
tv2=-1
shows=[]
n=int(input())
for i in range(n):
    l, r=map(int, input().split())
    shows.append((l, r))
shows.sort()
print(shows)
for l, r in shows:
    #print(l, r)
    if(tv1<l):
        tv1=r
    elif tv2<l:
        tv2=r
    else:
        print("NO")
        break
    print(tv1, tv2)
else:
    print("YES")
