n=int(input())
a=list(map(int, input().split()))
dict={}
for i in range(n):
    dict[a[i]]=i+1
k=int(input())
b=list(map(int, input().split()))
vasya=0
petya=0
for x in b:
    f=dict[x]
    vasya+=f
    petya+=(k-f+1)
print(vasya, petya)
    
    