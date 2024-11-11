n=int(input())
l=sorted(list(set(list(map(int,input().split())))))
print('0' if n==1 else l[1])