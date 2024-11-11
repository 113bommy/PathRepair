N=int(input())
S=input()
l=0
r=S[1:].count("E")
print(r)
answer=N

for i in range(N-1):
    if l+r<answer:
        answer=l+r
    if S[i]=="W":
        l+=1
    if S[i+1]=="E":
        r-=1
if l+r<answer:
    answer=l+r
print(answer)
