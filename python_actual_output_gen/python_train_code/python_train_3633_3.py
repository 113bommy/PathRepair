def find(s,c):
    l=len(s)
    return s[-c%l:]+s[:-c%l]

s=input()
for i in range(int(input())):
    a,b,c=map(int,input().split())
    s=s[:a-1]+find(s[a-1:b],c)+s[b:]
    print(s)
    #s=s1+s2+s3
print(s)