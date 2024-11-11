n ,k=map(int,input().strip().split())
s=input()
l=list(map(str,input().strip().split()))
diff=list()
h,i=0,0
while i < len(s):
    if s[i] not in l:
        i=i+1
    else:
        h = i
        while h + 1 < len(s) and s[h + 1] in l:
           h = h + 1
        diff.append(s[i:h+1])
        i = h +1
print(int(sum((len(i)*((len(i)+1)/2) for i in diff ))))