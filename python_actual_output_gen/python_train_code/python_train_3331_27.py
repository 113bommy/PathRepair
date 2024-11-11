n=int(input())
m=input().split(" ")
l=[]

for i in range(len (m)):
    if m!=0 and not(m[i] in l):
        l+=[m[i]]
print(len (l))
