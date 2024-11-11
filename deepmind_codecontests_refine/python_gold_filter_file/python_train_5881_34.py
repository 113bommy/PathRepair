n=int(input())
s1=input()
s2=input()
l1=[]
l2=[]
l3=[]
l4=[]
l5=[]
l6=[]
for i in range(0,n):
    l1.append(int(s1[i]))
    l2.append(int((s2[i])))
for i in range(0,n):
    l3.append(abs(l1[i]-l2[i]))
    l4.append((9-l1[i])+l2[i]+1)
    l5.append((9-l2[i])+l1[i]+1)
    l6.append(min((abs(l1[i]-l2[i])),((9-l1[i])+l2[i])+1,((9-l2[i])+l1[i])+1))
print(min(sum(l3),sum(l4),sum(l5),sum(l6)))