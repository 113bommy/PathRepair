k,n=map(int,input().split())
a=list(map(int,input().split())
a.append(a[0]+k)
al=[a[i+1]-a[i] for i in range(n)]
print(k-max(al))