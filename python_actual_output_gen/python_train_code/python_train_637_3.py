for s in[*open(0)][1:]:n,k=map(int,s.split());d=(k^n)&1+1;print(*(['YES']+[d]*(k-1)+[n-k*d+d],['NO'])[n&~k&1or k*d>n])
