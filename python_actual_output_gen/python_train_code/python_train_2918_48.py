red, blue= map(int,input().split())
p= min(red,blue)
q= max(red,blue)
if (q-p)%2==0:
    same_sock= (q-p)//2
else:
    same_sock=0
print(p, same_sock)