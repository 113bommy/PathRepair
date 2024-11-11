for s in[*open(0)][2::2]:
 a=sorted(map(int,s.split()));r=[0]
 for x in a:r+=max(r[-1],r[-min(x,len(r))]+1),
 print(r[-1])