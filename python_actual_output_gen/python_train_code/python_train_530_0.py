ar=[];d={}
for _ in range(int(input())):
    a,b=input().split()
    d[a]=d.get(a,0)+int(b)
    ar.append([a,d[a]])
max1=max(d.values())  
for i, j in ar:
    if d[i]==max1 and j==max1:
        print(i)
        break
        