n,s = list(map(int,input().split()));z=[]
for i in range(n):
    k,kk = input().split()
    c = (s*100 - int(k+kk if len(kk)==2 else k+"0"+kk))
    z.append(c%100) if c>0 else z.append(0)
print(max(z) if max(z)!=0 else -1)