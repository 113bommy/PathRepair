N,B=map(int,input().split())
S=list(map(int,input().split()))

odd=0
even=0

sep={}
sep2=[]
for i in range(N-1):
    if S[i]%2==0:
        odd+=1
    else:
        even+=1
    if odd==even:
        sep[i+1]=S[i+1]-S[i]
        sep2.append(abs(S[i+1]-S[i]))

sep2.sort()

count=0
for i in range(len(sep2)):
    B-=sep2[i]
    if B>=0:
        count+=1
print(count)
    