n.l = map(int,input().split())
al = [l+i for i in range(n)]
a = min(al,key=abs)
al.remove(a)
print(sum(al))