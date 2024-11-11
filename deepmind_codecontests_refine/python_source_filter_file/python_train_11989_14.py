from collections import defaultdict
di=defaultdict(lambda:0)
n=int(input())
for i in range(n):
        a=input()
        if di[a[0]]==0:
                di[a[0]]=1
        else:
                di[a[0]]+=1
s=0
for i in range(26):
        if di[chr(97+i)]>2:
                c=di[chr(97+i)]//2
                s1=(c*(c-1))/2
                c=di[chr(97+i)]-c
                s2=(c*(c-1))/2
                s=s1+s2
print(int(s))