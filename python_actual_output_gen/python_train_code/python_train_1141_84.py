t = int(input())
a = list(map(int,input().split()))
a.sort()
s=""
for i in a:
    s+=str(i)+" "
    print(s," ")