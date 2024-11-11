S=input()
a=0
for i in range(len(S)//2):
    if S[i]!=S[-1-i]:
        a+=1
print(a)