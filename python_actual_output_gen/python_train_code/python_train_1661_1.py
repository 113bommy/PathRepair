k=int(input())
n=sorted(list(map(int,input().split())))
if n[-1]>=n[0]+n[-2]:
    print("NO")
else:
    print("YES")
    for i in range(k-2):
        print(n[i],end=' ')
    print(n[-1],n[-2],end=' ')
    