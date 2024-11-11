a = [ i for i in range(1,2000) if i%3 != 0 and str(i)[-1] != '3']
for i in [*open(0)]:print(a[int(i.strip())-1])