n = input()
le = len(n)
l = [sum(10**(le-1-i) if int(y)>=x else 0 for i,y in enumerate(n)) for x in range(1,10)]
l = sorted([str(x) for x in l if x>0])
print (len(l))
print (' '.join(l))