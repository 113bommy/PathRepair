# import sys 
# sys.stdin=open("input1.in","r")
# sys.stdout=open("OUTPUX.out","w")
L=list(input())
S=set(L)
ans=((len(L)+1)*26)-len(S)
print(ans)
