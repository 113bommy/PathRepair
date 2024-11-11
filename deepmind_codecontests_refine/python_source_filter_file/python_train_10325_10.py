n=int(input())
a=list(map(int,input().split()))
if(sum(a)%2==0 and max(a)<=sum(a)):
    print("Yes")
else:
    print("NO")