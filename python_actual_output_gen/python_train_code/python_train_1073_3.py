vowels=list (i for i in "aeiouy")
n=int(input())
w=input()
ans=[1 for i in range(n)]

for i in range(n-1):
    if(w[i] in vowels and w[i+1] in vowels):
        ans[i]=0
    
wierd=''
for i in range(n):
    if(ans[i]==1):
        wierd+=w[i]
print(wierd)