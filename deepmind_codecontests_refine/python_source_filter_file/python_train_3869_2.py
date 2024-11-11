from collections import defaultdict
import sys
input=sys.stdin.readline
n=int(input())
u=[int(i) for i in input().split() if i!='\n']
freq,freq2=defaultdict(int),defaultdict(int)
for i in u:
    freq[i]+=1
for j in freq:
    freq2[freq[j]]+=1
#print(freq)
    ok=True
i=len(u)-1
#print(freq,freq2)
while  i>-1:
    #print(i,freq,set(freq.values()))
    if len(freq2)==2:
        aa,bb=sorted(list(freq2.items()))
        k1,v1 = aa
        k2,v2 = bb
        #print(aa,bb,freq2)
        if (k2-k1 == 1 and v2 == 1) or (k1 == 1 and v1 == 1):
            print(n)
            sys.exit()
    elif len(freq2)==1 :
        if len(set(u))==1 or set(freq.values())=={1}:
            print(i+1)
            exit()
    freq2[freq[u[i]]]-=1
    if freq2[freq[u[i]]]==0:
        del freq2[freq[u[i]]]
    freq[u[i]]-=1     
    if freq[u[i]]==0:
        del freq[u[i]]
    if freq[u[i]]:
        freq2[freq[u[i]]]+=1
    
    i-=1
    
          
