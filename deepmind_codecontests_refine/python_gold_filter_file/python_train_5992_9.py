n=int(input())
l=input().split()
l1=sorted([(int(l[i]),i+1) for i in range(n)])
#print(s)
for i in range(n//2):
    print(l1[i][1],l1[-1-i][1])
