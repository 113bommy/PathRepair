n=int(input())
l=list(map(int,input().split()))
print('YNeos'[max(l)*2>=sum(l)::2])