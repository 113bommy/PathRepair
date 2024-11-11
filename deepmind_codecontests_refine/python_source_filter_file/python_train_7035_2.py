def isSubSequence(pat,text,Done): 
    t = 0
    for i in range(len(text)):
        if t < len(pat) and text[i] == pat[t] and i + 1 not in Done: 
            t += 1
    return t == len(pat)
s=input();r=input();A=list(map(int,input().split()));n=len(A);low=0;high=n
while low<high:
    mid=(low+high)//2
    if isSubSequence(r,s,set(A[:mid])):
        low=mid+1
    else:high=mid-1
print(low-1)    