r,k =map(int, input().split())
S=[int(x) for x in input().split()]
t=min(S)
w=0
for i in range(len(S)):
     if S[i]%k!=0:
          w=-1
          break

     else:
        w=((S[i]-t)//k) + w
print(w)



