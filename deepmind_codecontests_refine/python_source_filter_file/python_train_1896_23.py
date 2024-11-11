p=int(input())
l=list(map(int,input().split()))
for i in range(p):
    if l[i] == 1:
        print("NO")
        continue
    if (l[i]-1)%14 == 0 or (l[i]-1)%14 ==1 or (l[i]-1)%14 ==2 or (l[i]-1)%14 ==3 or (l[i]-1)%14 ==4 or (l[i]-1)%14 ==5:
        print("YES")
    else:
        print("NO")
