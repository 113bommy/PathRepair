n,*aa=map(int, open(0).read().split())

aa.sort(reverse=True)

sum(aa[1::2][:n])