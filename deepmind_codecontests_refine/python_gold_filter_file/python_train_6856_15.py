N=int(input())

i=1
Sum=0
while Sum<N:
    Sum+=i
    i+=1

ans=[]
Top=i-1
while N:
    if N-Top>=0:
        N-=Top
        ans.append(Top)
    Top-=1

for j in ans:
    print(j)