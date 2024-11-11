a=input();b=int(input());z=0;s=0;q=dict();f=97;o=1
for i in map(int,input().split()):q[chr(f)]=i;f+=1
for i in a:s+=(o*q[i]);o+=1;z=max(q.values())
print(s+sum(i*z for i in range(o,o+b)))
