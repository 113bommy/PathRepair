input()
a=list(map(int,input().split()))
print("YNeos"[max(a)*2>=sum(a)::2])