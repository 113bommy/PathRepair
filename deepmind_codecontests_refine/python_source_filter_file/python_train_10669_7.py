n=input()
l=list(map(int,input().split()))
for x in l: print(sorted(l)[::-1].index(x))