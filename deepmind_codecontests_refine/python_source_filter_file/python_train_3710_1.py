h1,a1,c=map(int,input().split())
h2,a2=map(int,input().split())

l=[]
while(h2>0):
    print(h1,h2)
    if a2>=h1 and h2>a1:
        l.append("HEAL")
        h1+= c-a2
        print("*********")
    else:
        l.append("STRIKE")
        h2-=a1
        h1-=a2
        print("#########")

print(len(l))
for i in range(len(l)):
    print(l[i])