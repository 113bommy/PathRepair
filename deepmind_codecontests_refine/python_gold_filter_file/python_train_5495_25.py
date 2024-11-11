(k,n),(*a,) = [list(map(int,i.split())) for i in open(0)]
a.append(a[0]+k)
print(k - max(a[i+1]-a[i] for i in range(n)))