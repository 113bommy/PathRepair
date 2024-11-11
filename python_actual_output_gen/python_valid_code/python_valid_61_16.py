c=sum(list(map(int, input().split())))
m=sum(list(map(int, input().split())))
n=int(input())
if (c//5+(c%5!=0))+(m//10+(m%5!=10))<=n:
    print("YES")
else:
    print("NO")
   