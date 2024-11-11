n=int(input())
l=list(map(int,input().split()))
m=max(l)
if(m<26):
    print(0)
else:    
    print(max(l)-25)
