n,*aa=map(int, open(0).read().split())

aa.sort(reverse=True)

print(sum(aa[1::2][:n]))